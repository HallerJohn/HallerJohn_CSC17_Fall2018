/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FILEOUT.h"
#include <fstream>
#include <iostream>
using namespace std;


FileOut::FileOut(int game){
    ofstream out;
    if(game==1){
        out.open("Moves.txt",ios::trunc);
        out.close();
        out.open("Moves.txt");
        out<<"In this file you will find all of the moves you made in your games";
        out.close();
        out.open("Games.txt",ios::trunc);
        out.close();
        out.open("Games.txt");
        out<<"In this file you will find the results of all games played in a"
                " single program run.\r\n\r\n";
        out<<"Game #        Result\r\n";
        out.close();
        
    }
    out.open("Moves.txt",ios::app);
    out<<"\r\n\r\nGame     Turn        Move        Tile\r\n"<<endl;
    out.close();
    
}

