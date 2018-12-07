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
void addBeg(Link *,int);
void prntLst(Link *);


//Execution Begins Here
int main(int argc, char** argv) {
    //Create link pointer
    Link *head=new Link;
    
    
    //Pushback any integer into linked list;
    addBeg(head,1);
    addBeg(head,2);
    addBeg(head,3);
    addBeg(head,4);
    addBeg(head,5);
    addBeg(head,6);
    addBeg(head,7);
    addBeg(head,8);
    
    //Print List
    prntLst(head);
    cout<<endl;
    
    //Delete
    delete head;
    
    //Exit stage right!
    return 0;
}



void addBeg(Link *front,int x){
    Link *temp=new Link;
    temp->data=x;
    temp->node=front;
    front=temp;
}

void prntLst(Link *front){
    while(front!=nullptr){
        cout<<front->data<<endl;
        front=front->node;
    }
}