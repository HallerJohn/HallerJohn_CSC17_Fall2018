/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3TableInh.h
 * Author: John Haller
 *
 * Created on December 12, 2018, 9:01 PM
 */

#ifndef PROB3TABLEINH_H
#define PROB3TABLEINH_H
#include <fstream>
#include "Prob3Table.h"

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
    protected:
            T *augTable;                                  //Augmented Table with sums
    public:
            Prob3TableInherited(const char *,int,int);          //Constructor
            ~Prob3TableInherited(){delete [] augTable;};  //Destructor
            const T *getAugTable(void){return augTable;}; 
};

template <class T>
Prob3TableInherited<T>::Prob3TableInherited(const char* file, int row, int col) : Prob3Table<T>(file,row,col){
    augTable=new T[(this->rows+1)*(this->cols+1)];
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->cols;j++){
            augTable[i*(this->cols+1)+j]=this->table[(i*this->cols)+j];
        }
    }
    for(int i=0;i<row+1;i++){
        augTable[(i*(col+1))+col]=this->rowSum[i];
    }
    for(int i=0;i<col+1;i++){
        augTable[(row*(col+1))+i]=this->colSum[i];
    }
    augTable[((row+1)*(col+1))-1]=this->grandTotal;
}

#endif /* PROB3TABLEINH_H */

