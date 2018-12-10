/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FILEOUT.h"
#include <fstream>
#include <iostream>
using namespace std;


//Used for formatting of the files used for results and turns
FileOut::FileOut(int game){
    ofstream out;
    //If it is the first game played
    if(game==1){
        //open "Moves.txt" in truncate mode to clear it from the last time prgrm
        // was run
        out.open("Moves.txt",ios::trunc);
        out.close();
        //Open in normal mode to display message at top of file
        out.open("Moves.txt");
        out<<"In this file you will find all of the moves you made in your games";
        out.close();
        //Open "Games.txt" in truncate mode to clear it from the last time prgrm
        //was run
        out.open("Games.txt",ios::trunc);
        out.close();
        //open file normally for header at top of file
        out.open("Games.txt");
        out<<"In this file you will find the results of all games played in a"
                " single program run.\r\n\r\n";
        out<<"Game #        Result\r\n";
        out.close();
        
    }
    //Open file every time a new game is started, in append mode so it adds to
    //the end of the file
    out.open("Moves.txt",ios::app);
    out<<"\r\n\r\nGame     Turn        Move        Tile\r\n"<<endl;
    out.close();
    
}
