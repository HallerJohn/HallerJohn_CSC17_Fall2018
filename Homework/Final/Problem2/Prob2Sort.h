/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob2Sort.h
 * Author: John Haller
 *
 * Created on December 12, 2018, 10:05 PM
 */

#ifndef PROB2SORT_H
#define PROB2SORT_H

template<class T>
class Prob2Sort
{
private:
        int *index;                                 //Index that is utilized in the sort
public:
        Prob2Sort(){index=nullptr;};                   //Constructor
        ~Prob2Sort(){delete []index;};              //Destructor
        T * sortArray(const T*array,int row,bool ascending){
            for(int i=0;i<row;i++){
                for(int j=1;j<row;j++){
                    if(array[j]<array[i]){
                        T temp=array[j];
                        array[j]=array[i];
                        array[i]=temp;
                    }
                }
            }
            return array;
        }
        T * sortArray(const T*array,int rows,int cols,int idx,bool ascending){
            for(int i=0;i<rows*cols;i++){
                
            }
        }
}; 

#endif /* PROB2SORT_H */

