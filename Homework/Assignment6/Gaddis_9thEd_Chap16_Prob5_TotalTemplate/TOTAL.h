/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TOTAL.h
 * Author: John Haller
 *
 * Created on November 26, 2018, 3:54 PM
 */
#include <iostream>

#ifndef TOTAL_H
#define TOTAL_H

template <class T>
T total(T n){
    T answer=0;
    T temp;
    for(int i=0;i<n;i++){
        std::cin>>temp;
        answer+=temp;
    }
    return answer;
}

#endif /* TOTAL_H */

