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


template <class T>
T fileOut(T n){
    ofstream out;
    out.open("Moves.txt",ios::app);
    out<<n;
    out.close();
}


#endif /* FILETMP_H */

