/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "LINK.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void addEnd(Link *,int);
Link *findEnd(Link *);
void prntLst(Link *);


/*
    * This linked list reads in an integer for this purpose, but it could be
    * accepting an object. it then outputs it in FIFO order. making it a queue
*/


//Execution Begins Here
int main(int argc, char** argv) {
    //Create link pointer
    Link *head=new Link;
    
    //add any integer to end of linked list;
    addEnd(head,1);
    addEnd(head,2);
    addEnd(head,3);
    addEnd(head,4);
    addEnd(head,5);
    addEnd(head,6);
    addEnd(head,7);
    addEnd(head,8);
    
    //Print List
    prntLst(head);
    cout<<endl;
    
    
    //Delete
    delete head;
    
    //Exit stage right!
    return 0;
}


Link *findEnd(Link *front){
    Link *end=front;
    while(front!=nullptr){
        end=front;
        front=front->node;
    }
    return end;
}

void addEnd(Link *front,int x){
    Link *end=findEnd(front);
    Link *next=new Link;
    end->node=next;
    next->data=x;
    next->node=nullptr;   
}

void prntLst(Link *front){
    front=front->node;
    while(front!=nullptr){
        cout<<front->data<<endl;
        front=front->node;
    }
}

