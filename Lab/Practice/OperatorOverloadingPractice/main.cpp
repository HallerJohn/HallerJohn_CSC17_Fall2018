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
#include "NUMBERS.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Objects
    Number object1(5);
    Number object2(3);
    Number object3=object1+object2;
    Number object4=object1-object2;
    
    
    //Output data
    cout<<"Object1 is "<<object1.getNum()<<endl;
    cout<<"Object2 is "<<object2.getNum()<<endl;
    
    //Add and subtract objects
    cout<<"Object1 + Object2 = "<<object3.getNum()<<endl;
    cout<<"Object1 - Object2 = "<<object4.getNum()<<endl;
    
    //Check for equality
    if(object1==object2){
        cout<<"Object1 equals object2"<<endl;
    }
    else if(object1 > object2){
        cout<<"Object1 is greater than object2"<<endl;
    }
    else if(object1 < object2){
        cout<<"Object2 is greater than object1"<<endl;
    }
    
    //Increment object 1 prefix
    ++object1;
    cout<<"Object1 incremented by 1 prefix is "<<object1.getNum()<<endl;
    
    //Increment object 1 postfix
    object1++;
    cout<<"Object1 incremented by 1 postfix is "<<object1.getNum()<<endl;
    
    //Decrement object1 by 1 prefix
    --object1;
    cout<<"Object1 decremented by 1 prefix is "<<object1.getNum()<<endl;
    
    //Decrement object1 by 1 postfix
    object1--;
    cout<<"Object1 decremented by 1 postfix is "<<object1.getNum()<<endl;
    
    
    
    return 0;
}