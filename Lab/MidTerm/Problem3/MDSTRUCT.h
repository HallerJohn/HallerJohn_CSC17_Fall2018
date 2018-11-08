/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MDSTRUCT.h
 * Author: John Haller
 *
 * Created on October 26, 2018, 12:22 PM
 */

#ifndef MDSTRUCT_H
#define MDSTRUCT_H
#include "Array.h"

struct Stats{
    Array *mode;  //Array ADT contains number of modes and the modes themselves
    int modFreq;  //Mode Frequency
    float median; //Median of the array
    float avg;    //Average of the Array
};

#endif /* MDSTRUCT_H */

