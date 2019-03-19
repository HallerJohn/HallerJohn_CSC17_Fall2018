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
		Prob2Sort(){index=NULL;};                   //Constructor
		~Prob2Sort(){delete []index;};              //Destructor
		T * sortArray(const T*,int,bool);           //Sorts a single column array
		T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
};  



template <class T>
T * Prob2Sort <T>::sortArray(const T* point, int size, bool ascend){
    T* array=new T[size];
    index=new int[size];
    
    for(int i=0;i<size;i++){
        index[i]=i;
    }
    
    for(int i=0;i<size;i++){
        array[i]=*(point+i);
    }
    
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(ascend){
                if(array[i]<array[j]){
                    T temp=array[i];
                    array[i]=array[j];
                    array[j]=temp;
                    int indx=index[i];
                    index[i]=index[j];
                    index[i]=indx;
                }
            }else{
                if(array[i]>array[j]){
                    T temp=array[i];
                    array[i]=array[j];
                    array[j]=temp;
                    int indx=index[i];
                    index[i]=index[j];
                    index[j]=indx;
                }
            }
        }
    }
    return array;
}


template <class T>
T *Prob2Sort<T>::sortArray(const T* point, int rows, int cols, int chseCol, bool ascend){
    T* array=new T[rows*cols];
    index=new int[rows*cols];
    
    for(int i=0;i<(rows*cols);i++){
        index[i]=i;
    }
    
    for(int i=0;i<(rows*cols);i++){
        array[i]=*(point+i);
    }
    
    
    for(int i=chseCol-1;i<(rows*cols);i+=cols){
        for(int j=i+cols;j<(rows*cols);j+=cols){
            if(ascend){
                if(array[i]<array[j]){
                    for(int x=0;x<cols;x++){
                        T temp=array[(i-(chseCol-1))+x];
                        array[(i-(chseCol-1))+x]=array[(j-(chseCol-1))+x];
                        array[(j-(chseCol-1))+x]=temp;

                        int indx=index[(i-(chseCol-1))+x];
                        index[(i-(chseCol-1))+x]=index[(j-(chseCol-1))+x];
                        index[(j-(chseCol-1))+x]=indx;
                    }
                }
            }else{
                if(array[i]>array[j]){
                    for(int x=0;x<cols;x++){
                        T temp=array[(i-(chseCol-1))+x];
                        array[(i-(chseCol-1))+x]=array[(j-(chseCol-1))+x];
                        array[(j-(chseCol-1))+x]=temp;

                        int indx=index[(i-(chseCol-1))+x];
                        index[(i-(chseCol-1))+x]=index[(j-(chseCol-1))+x];
                        index[(j-(chseCol-1))+x]=indx;
                    }
                }
            }
        }
    }
    return array;
}

#endif /* PROB2SORT_H */

