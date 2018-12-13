/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob3Table.h
 * Author: John Haller
 *
 * Created on December 12, 2018, 8:51 PM
 */

#ifndef PROB3TABLE_H
#define PROB3TABLE_H

#include <fstream>
#include <iostream>
using namespace std;

template<class T>
class Prob3Table
{
    protected:
            int rows;                                 //Number of rows in the table
            int cols;                                 //Number of cols in the table
            T *rowSum;                                //RowSum array
            T *colSum;                                //ColSum array
            T *table;                                 //Table array
            T grandTotal;                             //Grand total
            void calcTable(void);                     //Calculate all the sums
    public:
            Prob3Table(const char *,int,int);    
            Prob3Table();//Constructor then Destructor
            ~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
            const T *getTable(void){return table;};
            const T *getRowSum(void){return rowSum;};
            const T *getColSum(void){return colSum;};
            T getGrandTotal(void){return grandTotal;};
};

template <class T>
Prob3Table<T>::Prob3Table(const char* file, int row, int col){
    rows=row;
    cols=col;
    table=new T[rows*cols];
   
    ifstream in;
    in.open(file);
    for(int i=0;i<(rows*cols);i++){
        in>>table[i];
    }
    in.close();
    calcTable();
}

template <class T>
void Prob3Table<T>::calcTable(){
    rowSum=new T[rows];
    for(int i=0;i<rows;i++){
        rowSum[i]=0;
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            rowSum[i]+=table[i*cols+j];
        }
    }
    
    colSum=new T[cols];
    for(int i=0;i<cols;i++){
        colSum[i]=0;
    }
    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++){
            colSum[i]+=table[i+(cols*j)];
        }
    }
    grandTotal=0;
    for(int i=0;i<rows;i++){
        grandTotal+=rowSum[i];
    }
}

#endif /* PROB3TABLE_H */

