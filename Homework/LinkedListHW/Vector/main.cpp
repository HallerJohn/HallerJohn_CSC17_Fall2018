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
void pushBck(Link *,int);
Link *findEnd(Link *);
void prntLst(Link *);
int getIndx(Link *,int);


//Execution Begins Here
int main(int argc, char** argv) {
    //Create link pointer
    Link *head=new Link;
    
    //Pushback any integer into linked list;
    pushBck(head,1);
    pushBck(head,2);
    pushBck(head,3);
    pushBck(head,4);
    pushBck(head,5);
    pushBck(head,6);
    pushBck(head,7);
    pushBck(head,8);
    
    //Print List
    prntLst(head);
    cout<<endl;
    
    
    //get the desired index from the list, remember it starts at 0
    cout<<"The desired index is "<<getIndx(head,1)<<endl;
    
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

void pushBck(Link *front,int x){
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

int getIndx(Link *front,int index){
    front=front->node;
    for(int i=0;i<index;i++){
        front=front->node;
    }
    return front->data;
}