/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ABSVAL.h
 * Author: John Haller
 *
 * Created on November 26, 2018, 3:48 PM
 */

#ifndef ABSVAL_H
#define ABSVAL_H

template <class T>
T absVal(T a){
    return (a>=0?a:a*-1);
}

#endif /* ABSVAL_H */

