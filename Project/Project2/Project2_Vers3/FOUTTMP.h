/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FOUTTMP.h
 * Author: John Haller
 *
 * Created on December 8, 2018, 1:50 PM
 */
#include <iostream>
#include <fstream>
using namespace std;

#ifndef FOUTTMP_H
#define FOUTTMP_H

//This template is used for writing to the "Games.txt" file
template <class T>
T fleOutG(T n){
    ofstream out;
    //open file
    out.open("Games.txt",ios::app);
    //write to file
    out<<n;
    //close file
    out.close();
}

#endif /* FOUTTMP_H */

