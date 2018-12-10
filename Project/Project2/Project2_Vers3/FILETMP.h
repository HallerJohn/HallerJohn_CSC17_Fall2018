/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FILETMP.h
 * Author: John Haller
 *
 * Created on December 7, 2018, 9:39 PM
 */
#include <iomanip>
#include <fstream>
using namespace std;

#ifndef FILETMP_H
#define FILETMP_H

//The purpose of this template is to write to "Moves.txt"
template <class T>
T fileOut(T n){
    ofstream out;
    //open file
    out.open("Moves.txt",ios::app);
    //write to file
    out<<n;
    //close file
    out.close();
}


#endif /* FILETMP_H */

