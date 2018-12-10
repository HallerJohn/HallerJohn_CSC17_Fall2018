/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

//User Libraries
#include "BOMBFLD.h"
#include "PLAYFLD.h"
#include "FILEOUT.h"
#include "FILETMP.h"
#include "FOUTTMP.h"
#include "IEXIST.h"
#include "FIELD.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//The intro function outputs the introduction as well as rules and such
void intro();
//The choice function inputs the players command and which tile it applies to
void choice(char &,int &,int &);
//The check function detects if the tile selected is a bomb or not, then drives
//the program further depending on the result and also returns life status as bool
bool check(Player *,Bomb *,int,int);
//The fndBomb function checks the surrounding 8 tiles for bombs and sets the
//tile to be the number of bombs found. If it finds no bombs it will drive
//the program further
void fndBomb(Player *,Bomb *,int,int);
//The recurs function starts the recursion process if no bombs were found around
//the chosen tile. It will loop the check function on the tiles to the
//north, south,east, and west of the chosen tile.
void recurs(Player *,Bomb *,int,int);
//The death function is called when the player chooses a tile with a bomb on it.
//it simply outputs a brief message and ends the program.
void death(Player *);
//The flag function is what is responsible for the win condition of the game.
//It handles both the flagging of tiles, as well as checking to see if the flag
//matches with a bomb or not. Once all of the bombs have been flagged the user
//will win
void flag(Player *,Bomb *,int,int,int &,int &);
//The setFile function is used to set variables in the fileOut object
void setFile(FileOut *,int,int,char);
//The write function writes turn data for each game to "Moves.txt"
void write(FileOut *);
//The writeGme function writes game data to ""Games.txt"
void writeGme(FileOut *,char);
//Cleanup function deletes dynamic pointers to objects
void cleanup(Player *,Bomb *, FileOut *);
//Function to increment the counter for turns,used for file outputting.
void incTurn(FileOut *);
//Tests whether the desired bombs is greater than 0 or not.(Exceptions)
void tstBomb(int);

//Execution Begins Here
int main(int argc, char** argv) {
    
    //Variables
    //The number of rows the player wants to play with
    int nRows;
    //The number of columns the player wants to play with
    int nCols;
    //The number of bombs the player wants to play with
    int bombs;
    //The row the player has chosen for their turn
    int chosenR;
    //The col the player has chosen for their turn
    int chosenC;
    //The action the player is going to take
    char command;
    //The players life status
    bool alive;
    //The current game number
    int games=0;
    
    //Intro
    intro();
    //Character for if you want to replay or not
    char replay;
    do{
        alive=true;
        //The count of flags successfully placed on bombs
        int flagCnt=0;
        //The number of flags placed
        int nFlags=0;
        //Input size of grid and number of bombs
        cout<<"We will now construct your minefield."<<endl;
        cout<<"How many rows would you like in your field?"<<endl;
        cin>>nRows;
        cout<<"How many columns would you like in your field?"<<endl;
        cin>>nCols;
        cout<<"How many bombs would you like to play with?"<<endl;
        cin>>bombs;
        
        //Exception throwing/handling time
        try{
            //Tests to see if bombs are negative or not, throws if so
            tstBomb(bombs);
        }
        //Catch the exception if thrown
        catch(string exception){
            cout<<exception<<endl;
            exit(EXIT_FAILURE);
        }
        //Increment game counter
        games++;

        //Pointer for the player grid, this will be the field that the player sees,
        //and interacts with.
        Player *pPoint=new Player(nRows,nCols);
        //Pointer for the bomb grid, this will not be visible to the player, and 
        //they will not be able to interact with it.
        Bomb *bPoint=new Bomb(nRows,nCols,bombs);

        //Create pointer for FileOut class, this is purely used for writing to
        //files. not visible to player.
        FileOut *fPoint=new FileOut(games);

        //Print bomb field for testing
    //    bPoint->prtFld();

        //Print player field
        pPoint->prtFld();
        //Set game counter in fPoint object
        fPoint->setGame(games);
        //set replay so that game doesnt automatically replay
        replay='n';
        
        
        //Loop to play game
        //This do-while is to loop the process of taking turns until the game is over
        do{
            //input players decision
            //this do-while is used to loop the input process until appropriate
            //values have been inputted(input validation)
            do{
                //Run the choice function to input their turn
                choice(command,chosenR,chosenC);
                //If the user inputs values outside of their specified range
                //The program will prompt them to try again
                if(chosenR>nRows-1||chosenC>nCols-1){
                    cout<<"Invalid Input, Try again"<<endl;
                }
            //End of loop for input validation
            }while(chosenR>nRows-1||chosenC>nCols-1);
            //Increment turn counter in fPoint object
            fPoint->incTurn();
            //Set members in fPoint object for writing to file
            setFile(fPoint,chosenR,chosenC,command);
            //Write turn data to file
            write(fPoint);

            //If player selects a tile
            //This is used to drive the program if the player wants to select a tile
            if(command=='s'){
                //Check to see if the tile is a bomb and drive program depending on result
                alive=check(pPoint,bPoint,chosenR,chosenC);
                //Print the field so user can see result of their action
                if(alive)pPoint->prtFld();
            //If the player chooses to flag a tile
            }else if(command=='f'){
                //Runs the flag function to flag the chosen tile, as well as increment
                //flagCnt if necessary
                flag(pPoint,bPoint,chosenR,chosenC,flagCnt,nFlags);
            }
            //If the player is dead break out of game
            if(!alive)break;
        //End of loop for the game, when this ends the player has won.
        //The condition is set this way so that the player needs to have flagged the
        //exact amount of bombs, that way they cannot flag every single tile and then win.
        }while(flagCnt!=bombs || nFlags!=bombs);

        if(alive){
            cout<<"Congratulations you have won!"<<endl;
            //Write vitory to Games.txt
            writeGme(fPoint,'V');
            //Write loss to Games.txt
        }else writeGme(fPoint,'L');


        //Delete pointers to objects
        cleanup(pPoint,bPoint,fPoint);
        
        cout<<"Would you like to play again? [y,n]"<<endl;
        cin>>replay;
    }while(replay=='y');
    
    
    //Create an array of objects that exists for a secret reason
    int SIZE=5;
    //Declaring impObjs(important objects) of the IExist class
    IExist impObjs[SIZE];
    
    //I dont even want to explain this in text..
    for(IExist i;i<SIZE;++i){
        impObjs[i.getX()].incCnt();
        ++i;
        --i;
    }
    ofstream out;
    out.open("Important.txt");
    //output results of above process to "Important.txt"
    out<<impObjs[0].getCnt();
    out.close();
    
    //STL stuff 
    vector <int>v;
    for(int i=0;i<SIZE;i++){
        v.push_back(i);
    }
    out.open("VectorsArePartOfTheSTL.txt");
    for(int i=0;i<SIZE;i++){
        out<<v[i];
    }
    out.close();
    
    //Polymorphism
    Player *object;
    Field *point=object;
    object->poly();
    //Exit stage right!
    return 0;
}

//The choice function takes the players command, the chosen row, and the chosen col
//It returns nothing
//It is used to input the command of the player
void choice(char &command,int &chosenR,int &chosenC){
    cout<<"What action would you like to take?"<<endl;
    cin>>command>>chosenR>>chosenC;
    //This is done to offset the row for ease of use with array indexes
    chosenR-=1;
    //This is done to offset the col for ease of use with arrat indexes
    chosenC-=1;
}

//The check function takes the pointer to Player class, pointer to Bomb class,
//  the chosen row, and the chosen column
//It returns a boolean
//This function determines if the chosen tile is a bomb or not, and then further
//  drives the program depending on the result

bool check(Player *pPoint,Bomb *bPoint,int chosenR,int chosenC){
    //Checks to see if the chosen tile is bomb
    if(bPoint->getBomb(chosenR,chosenC)=='B'){
        //If it is it sets the tile to = 'B'
        pPoint->setFld(chosenR,chosenC,'B');
        //Calls death function to output result and return false for alive
        death(pPoint);
        return false;
    }
    //If the chosen tile is not a bomb 
    else if(bPoint->getBomb(chosenR,chosenC)=='X'){
        //It will then check the surrounding 8 tiles for bombs
        fndBomb(pPoint,bPoint,chosenR,chosenC);
        return true;
    }
}

//The fndBomb function takes the pointer to Player class, pointer to Bomb class,
//  the chosen row, and the chosen column
//It returns nothing
//This function checks the surrounding tiles for bombs, and then sets the chosen
//  tile to = the amount found. If none are found the program continues onto recursion
void fndBomb(Player *pPoint,Bomb *bPoint,int row,int col){
    //This if checks if the tile has been checked already to prevent infinite looping
    if(pPoint->getFld(row,col)!=' '){
        //Counter for bombs found
        char bombCnt=0;
        //Check top left
        if(bPoint->getBomb(row-1,col-1)=='B')bombCnt++;
        //Check top middle
        if(bPoint->getBomb(row-1,col)=='B')bombCnt++;
        //Check top right
        if(bPoint->getBomb(row-1,col+1)=='B')bombCnt++;
        //Check middle left
        if(bPoint->getBomb(row,col-1)=='B')bombCnt++;
        //Check middle right
        if(bPoint->getBomb(row,col+1)=='B')bombCnt++;
        //Check bottom left
        if(bPoint->getBomb(row+1,col-1)=='B')bombCnt++;
        //Check bottom middle
        if(bPoint->getBomb(row+1,col)=='B')bombCnt++;
        //Check bottom right
        if(bPoint->getBomb(row+1,col+1)=='B')bombCnt++;

        //If no bombs are found around the tile
        if(bombCnt==0){
            //Set the tile equal to ' '
            pPoint->setFld(row,col,' ');
            //Call the recursion function to check tiles to the N,S,E,W
            recurs(pPoint,bPoint,row,col);
        }
        //If some amount of bombs are found
        else{
            //Set the chosen tile = to the number of bombs found.(+48 so that it
            //displays correctly as a character)
            pPoint->setFld(row,col,bombCnt+48);
        }
    }
}

//The recurs function takes the pointer to Player class, pointer to Bomb class,
//  the chosen row, and the chosen column
//It returns nothing
//This function's sole purpose is the recursively check all tiles to the N,S,E,W
//  of the chosen tile
void recurs(Player *pPoint,Bomb *bPoint,int row,int col){
    check(pPoint,bPoint,row-1,col);
    check(pPoint,bPoint,row,col-1);
    check(pPoint,bPoint,row,col+1);
    check(pPoint,bPoint,row+1,col);
}
//The death function takes the pointer to the Player class
//It returns nothing
//This class is used to output a death message as well as exit the program.
//  This is only done if the player selects a bomb as their chosen tile.
void death(Player *pPoint){
    //Print the field one final time
    pPoint->prtFld();
    //Death message, I know its beautiful
    cout<<"You hit a bomb and died, rip."<<endl;
}
//The flag function takes the pointer to the Player class, the pointer to the Bomb class,
//  the chosen row, the chosen col, the flagCnt by reference, as well as nFlags by reference
//It returns nothing.
//This program is used to both set the chosen tile as a flag, 'F', and to count
//  the times the player succesfully marked a flag, and the amount of flags placed
void flag(Player *pPoint,Bomb *bPoint,int row,int col,int &flagCnt,int &nFlags){
    //If the chosen tile is already a flag
    if(pPoint->getFld(row,col)=='F'){
        //Then unflag it
        pPoint->setFld(row,col,'X');
        //If tile was unflagged decrement flag counter
        nFlags--;
    }
    //otherwise do this
    else {
        //Set the chosen tile to = flag, 'F'
        pPoint->setFld(row,col,'F');
        //Increment number of flags
        nFlags++;
    }
    //If the flag was placed on a bomb, increment flagCnt;
    if(bPoint->getBomb(row,col)=='B')flagCnt++;
    //Print field after players move
    pPoint->prtFld();
}


/*The intro function takes nothing and returns nothing.
 * it is used to display the introduction as well as the rules and how to
 * format your input
 */
void intro(){
    cout<<"Welcome to MINESWEEPER!"<<endl;
    cout<<"The objective is to flag all of the tiles that "
            <<"contain a bomb"<<endl;
    cout<<"First you will input how many bombs you "
            <<"want to play with. "<<endl;
    cout<<"Next select a tile"<<endl;
    cout<<"You do this by entering your action, 's' for select, "
            <<"or 'f' for flag"<<endl;
    cout<<"Follow your action with a space and then a number "
            <<"for what row you want to select"<<endl;
    cout<<"Followed by another space and a number for what "
            <<"column you want"<<endl;
    cout<<"An example input is [s 4 5]"<<endl<<endl;
}

/*The setFile function takes a pointer to fileOut class, chosen row,chosen col,
 *      and chosen action
 * It returns nothing
 * Its purpose is to set members in the fileOut class in order to prepare for 
 *      file writing
 */
void setFile(FileOut *fPoint,int row,int col,char action){
    fPoint->setRow(row+1);
    fPoint->setCol(col+1);
    fPoint->setAct(action);
}

/*The write function takes a pointer to fileOut class.
 * It returns nothing
 * It's purpose is to send info to the fileOut template to be written to Moves.txt
 */
void write(FileOut *fPoint){
    fileOut("   ");
    fileOut(fPoint->getGame());
    fileOut("        ");
    fileOut(fPoint->getTurn());
    fileOut("          ");
    fileOut(fPoint->getAct());
    fileOut("         ");
    fileOut(fPoint->getRow());
    fileOut(" , ");
    fileOut(fPoint->getCol());
    fileOut("\r\n");
}

/*The wrtieGme function takes a pointe to the fileOut class, and the result of the game
 * It returns nothing
 * The purpose of this function is to send info to the fleOutG template, and be
 *      written to Games.txt
 */
void writeGme(FileOut *fPoint,char result){
    fleOutG("   ");
    fleOutG(fPoint->getGame());
    fleOutG("             ");
    fleOutG(result);
    fleOutG("\r\n");
}

/*The cleanup function takes pointers to the player class, the bomb class, and
 *      the fileOut class.
 * It returns nothing
 * It's purpose is to delete dynamic pointers to classes 
 */
void cleanup(Player *pPoint,Bomb *bPoint, FileOut *fPoint){
    delete pPoint;
    delete bPoint;
    delete fPoint;
}

/*The tstBomb function takes the number of bombs in the game
 * It returns nothing
 * It's purpose is to test if the player input a negative number of bombs, and
 *      will throw an exception if so.
 */
void tstBomb(int bombs){
    if(bombs<=0){
        string exception="Error, cannot have less than 1 bomb";
        throw exception;
    }
}