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


template <class T>
T fleOutG(T n){
    ofstream out;
    out.open("Games.txt",ios::app);
    out<<n;
    out.close();
}

#endif /* FOUTTMP_H */

