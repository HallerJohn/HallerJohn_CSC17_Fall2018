/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NUMBERS.h"
#include <cstdlib>
using namespace std;

Numbers::Numbers(){
    cout<<"Enter your number to be converted [0-9999]"<<endl;
    cin>>number;
    if(number<0||number>9999){
        cout<<"Invalid number"<<endl;
        exit(EXIT_FAILURE);
    }
    convert();
    cout<<"The answer is"<<answer<<endl;
}


void Numbers::convert(){
    bool isSpec=false;
    int num=number;
    int n1000=num/1000;
    num-=(n1000*1000);
    int n100=num/100;
    num-=(n100*100);
    int n10=num/10;
    int n1=num%10;
    if(n1000>0){
        answer+=" ";
        answer+=one(n1000-1);
        answer+=" thousand";
    }
    if(n100>0){
        answer+=" ";
        answer+=one(n100-1);
        answer+=" hundred";
    }
    if(num>9&&num<20){
        answer+=spec(n1);
    }
    else if(n10>1){
        answer+=" ";
        answer+=ten(n10-2);
        isSpec=true;
    }
    if(n1>0&&isSpec){
        answer+=" ";
        answer+=one(n1-1);
    }
    if(num==0)answer+="zero";
}