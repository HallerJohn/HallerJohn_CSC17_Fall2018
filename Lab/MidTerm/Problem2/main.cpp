/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries
#include "EmpData.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void *flStruc(empData *,int);
void prStruc(empData *,int);
float calcPay(empData *,int);
float cnvtEng(empData *,int);
void destroy(empData *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char repeat='y';
    int size=100;
    int empCnt=0;
    empData *emplyee=new empData[size];
    for(int i=0;repeat=='y'||repeat=='Y';i++){
       flStruc(emplyee,i);
       empCnt++;
       cout<<"Would you like to input another employee? [y/n]"<<endl;
       cin>>repeat;
    }
    //ICalculate pay
    for(int i=0;i<empCnt;i++){
        calcPay(emplyee,i);
    }
    
    //Process/Map inputs to outputs
    for(int i=0;i<empCnt;i++){
        cnvtEng(emplyee,i);
    }
    
    //Output data
    for(int i=0;i<empCnt;i++){
        prStruc(emplyee,i);
    }
    
    //Delete array of structures
    destroy(emplyee);
    //Exit stage right!
    return 0;
}
void *flStruc(empData *emplyee,int i){
    if(i>0)cin.ignore();
    getline(cin,emplyee[i].company);
    getline(cin,emplyee[i].address);
    getline(cin,emplyee[i].name);
    cin>>emplyee[i].hours;
    cin>>emplyee[i].rate;
}
void prStruc(empData *emplyee,int i){
    cout<<"Company :"<<emplyee[i].company<<endl;
    cout<<"Address :"<<emplyee[i].address<<endl;
    cout<<"Name :"<<emplyee[i].name;
    cout<<" Amount :$"<<emplyee[i].finlPay<<endl;
    cout<<"Amount :"<<emplyee[i].engPay<<endl;
    cout<<"Signature line ____________________________"<<endl<<endl<<endl;
}
float calcPay(empData *emplyee,int i){
    float hours=emplyee[i].hours;
    float rate=emplyee[i].rate;
    if(hours<=40){
        emplyee[i].finlPay=hours*rate;
    }if(hours>40&&hours<=50){
        emplyee[i].finlPay=40*rate;
        emplyee[i].finlPay=emplyee[i].finlPay+((hours-40)*rate*2);
    }if(hours>50){
        emplyee[i].finlPay=40*rate;
        emplyee[i].finlPay=emplyee[i].finlPay+(10*rate*2);
        emplyee[i].finlPay=emplyee[i].finlPay+((hours-50)*rate*3);
    }
}
float cnvtEng(empData *emplyee,int i){
    float finPay=emplyee[i].finlPay;
    int n100s=finPay/100;
    finPay-=n100s*100;
    int n10s=finPay/10;
    if(n10s>1)finPay-=n10s*10;
    int n1s=finPay;
    static string hundred[]={" ","one","two","three","four","five","six","seven",
        "eight","nine"};
    static string tens[]={" "," ","twenty","thirty","fourty","fifty","sixty","seventy",
        "eighty","ninety"};
    static string ones[]={" ","one","two","three","four","five","six","seven","eight",
        "nine","ten","eleven","twelve","thirteen","fourteen","fifteen",
        "sixteen","seventeen","eighteen","nineteen"};
    if(n100s>0){
        emplyee[i].engPay+=hundred[n100s];
        emplyee[i].engPay+=" hundred ";
    }
    if(n10s>0){
        emplyee[i].engPay+=" and ";
        emplyee[i].engPay+=tens[n10s];
    }
    if(n1s>0){
        emplyee[i].engPay+=" and ";
        emplyee[i].engPay+=ones[n1s];
    }
    emplyee[i].engPay+=" Dollars";
}
void destroy(empData *emplyee){
    delete []emplyee;
}