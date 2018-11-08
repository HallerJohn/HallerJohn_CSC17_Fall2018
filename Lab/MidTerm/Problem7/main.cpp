/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int number;//number to be factored
    //Initialize Variables
    cin>>number;//input number
    cout<<"The factors of "<<number<<" are :";
    //Evens
    while(number%2==0){//if number is even
        cout<<"2,";//output 2 as a factor
        number/=2;//divide it by 2
    }
    //Odds
    for(int i=3;i<sqrt(number);i+=2){//start at three because 1 and 2 are taken care of already
        while(number%i==0){          //i increments by 2 because all even numbers are dealt with
            cout<<i<<",";
            number/=i;
        }
    }
    //Primes
    if(number>2)cout<<number<<endl;//if the number is prime before/after it has 
                                   //been modified
    //Exit stage right!
    return 0;
}