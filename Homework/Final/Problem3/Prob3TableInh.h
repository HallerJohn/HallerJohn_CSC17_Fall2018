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



template<class T>
class Prob3TableInherited:public Prob3Table<T>{
    protected:
        T *augTable;                                  //Augmented Table with sums
    public:
            Prob3TableInherited(char *,int,int);          //Constructor
            ~Prob3TableInherited(){delete [] augTable;};  //Destructor
            const T *getAugTable(void){return augTable;}; 
};

#endif /* PROB3TABLEINH_H */

