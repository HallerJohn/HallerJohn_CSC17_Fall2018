/* 
 * File:   main.cpp
 * Author: John Haller
 * Created on August 29, 2018, 12:58 PM
 * Purpose:  Class work
 */

//System Libraries
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

//User Libraries
#include "EmpData.h"
#include "CustAct.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();
//Problem 4 functions
void encrypt(char [],int);
void decrypt(char [],int);
//Problem 2 functions
void *flStruc(empData *,int);
void prStruc(empData *,int);
float calcPay(empData *,int);
float cnvtEng(empData *,int);
void destroy(empData *);
//Problem 1 functions
Account *flStruc();//fill contents of structure and return pointer to it
float calcBal(Account *);//calculate balance
void ptStruc(Account *);//print contents of structure
void cleanUp(Account *);//Cleanup

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm1(){
    cout<<"Problem 1"<<endl;
    //Declare Variables
    Account *point=flStruc();//pointer to structure
    
    //Initialize Variables
    
    //Process/Map inputs to outputs
    point->endBal=calcBal(point);//Calculate final balance
    
    //Output data
    ptStruc(point);//Print data
    
    //Delete pointer to structure
    cleanUp(point);
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm2(){
    cout<<"Problem 2"<<endl;
    cout<<"Enter information on employees"<<endl;
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
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 3
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm3(){
    cout<<"Problem 3"<<endl;
    cout<<"This problem is not included in this menu."<<endl;
    cout<<"It will be included in the folder that this was sent in."<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm4(){
    cout<<"problem 4"<<endl;
    cout<<"Input a number to be encrypted or decrypted"<<endl;
    //Declare Variables
    char choice=' ';
    int size=4;
    char data[size];
    //Initialize Variables
    cout<<"Input the data"<<endl;
    cin>>data;
    for(int i=0;i<size;i++){
        if(data[i]-48<0||data[i]-48>7){
            cout<<"Incorrect number input, exiting program"<<endl;
            exit(EXIT_FAILURE);
        }
    }
    
    cout<<"Would you like to encrypt [e], or decrypt [d]?"<<endl;
    cin>>choice;
    if(choice=='e')encrypt(data,size);
    else decrypt(data,size);
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 5
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm5(){
    cout<<"Problem 5"<<endl;
    //Output data
    cout<<"Char =5!"<<endl;
    cout<<"Unsigned Char =5!"<<endl;
    cout<<"Int =7!"<<endl;
    cout<<"Unsigned int =8!"<<endl;
    cout<<"Short =7!"<<endl;
    cout<<"Unsigned Short =8!"<<endl;
    cout<<"Long =12!"<<endl;
    cout<<"Unsigned Long =12!"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 6
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm6(){
    cout<<"Problem 6"<<endl;
    
    //   2.875
    cout<<"2.875"<<endl;
    cout<<"In binary = 10.111"<<endl;
    cout<<"In octal  = 2.7"<<endl;
    cout<<"In hexa   = 2.e"<<endl;
    cout<<"Float representation = 5c000004"<<endl;
    //   -2.875
    cout<<"-2.875"<<endl;
    cout<<"In binary = -10.111"<<endl;
    cout<<"In octal  = -2.7"<<endl;
    cout<<"In hexa   = -2.e"<<endl;
    cout<<"Float representation = dc000004"<<endl;
    //   0.1796875
    cout<<"0.1796875"<<endl;
    cout<<"In binary = 0.0010111"<<endl;
    cout<<"In octal  = .134"<<endl;
    cout<<"In hexa   = .2e"<<endl;
    cout<<"Float representation = 17000087"<<endl;
    //   0.1796875
    cout<<"-0.1796875"<<endl;
    cout<<"In binary = -0.0010111"<<endl;
    cout<<"In octal  = -.134"<<endl;
    cout<<"In hexa   = -.2e"<<endl;
    cout<<"Float representation = 97000087"<<endl;
    //   59999901
    cout<<"59999901"<<endl;
    cout<<"In binary = 0.10110011001100110011"<<endl;
    cout<<"In octal  = 0.5463146"<<endl;
    cout<<"In hexa   = .b3333"<<endl;
    //   59999902
    cout<<"59999902"<<endl;
    cout<<"In binary = 1011.0011001100110011"<<endl;
    cout<<"In octal  = 13.146314"<<endl;
    cout<<"In hexa   = b.3333"<<endl;
    //   A66667FE
    cout<<"A66667FE"<<endl;
    cout<<"In binary = -0.00000100110011001101"<<endl;
    cout<<"In octal  = -0.01146316"<<endl;
    cout<<"In hexa   = -.04ccce"<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 7
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void prblm7(){
    cout<<"problem 7"<<endl;
    cout<<"Input a number to be factored"<<endl;
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
}
void encrypt(char data[],int size){
    int digit[size];
    for(int i=0;i<size;i++){
        digit[i]=(data[i]-48+5)%8;
    }
    data[0]=digit[2]+48;
    data[2]=digit[0]+48;
    data[1]=digit[3]+48;
    data[3]=digit[1]+48;
    
    cout<<"The encoded data is :";
    for(int i=0;i<size;i++){
        cout<<data[i];
    }
}
void decrypt(char data[],int size){
    int digit[size];
    for(int i=0;i<size;i++){
        digit[i]=(data[i]-48-5+8)%8;
    }
    data[0]=digit[2]+48;
    data[2]=digit[0]+48;
    data[1]=digit[3]+48;
    data[3]=digit[1]+48;
    
    cout<<"The encoded data is :";
    for(int i=0;i<size;i++){
        cout<<data[i];
    }
}
void *flStruc(empData *emplyee,int i){
    cout<<"Enter employee's company"<<endl;
    cin.ignore();
    getline(cin,emplyee[i].company);
    cout<<"Enter employee's address"<<endl;
    getline(cin,emplyee[i].address);
    cout<<"Enter employee's name"<<endl;
    getline(cin,emplyee[i].name);
    cout<<"Enter employee's hours worked"<<endl;
    cin>>emplyee[i].hours;
    cout<<"Enter employee's pay rate"<<endl;
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

Account *flStruc(){
    Account *point=new Account;//Create pointer to structure
    point->totChck=0;//initialize to 0
    point->totDeps=0;//initialize to 0
    cout<<"Enter your name"<<endl;
    cin.ignore();
    getline(cin,point->name);//input name on account
    cout<<"Enter your street address"<<endl;
    getline(cin, point->address);//input address 
    cout<<"Enter your 5 digit account number"<<endl;
    cin>>point->acctNum;//Input account number
    if(point->acctNum<10000||point->acctNum>99999){//Make sure 5 digits
        cout<<"Invalid account number, Exiting program"<<endl;
        exit(EXIT_FAILURE);
    }
    cout<<"Enter your balance at the beginning of the month"<<endl;
    cin>>point->begBal;//input balance at start of month
    point->endBal=point->begBal;
    cout<<"Enter the amount of each check written this month, when done enter 0"
            <<endl;
    float check=0;//Current check being processed
    do{
        cin>>check;
        point->totChck+=check;//add current check onto total check
    }while(check!=0);//loop until user is finished
    cout<<"Enter the amount of each deposit this month, when done enter 0"
            <<endl;
    float deposit=0;//current deposit being processed
    do{
        cin>>deposit;//input current deposit
        point->totDeps+=deposit;//add current deposit onto total
    }while(deposit!=0);//loop until user is done
    return point;//return pointer to structure
}
float calcBal(Account *point){
    int ovrDraw=20;//overdraw fee of $20
    float curBal=point->begBal;//current balance
    curBal-=point->totChck;//subtract checks
    curBal+=point->totDeps;//add deposits
    cout<<endl;
    if(curBal<0){//if account is negative add of fee
        cout<<"Your account has been overdrawn, you have been charged a $20"<< 
                " fee"<<endl;
        curBal-=ovrDraw;//subtract fee from total
    }
    cout<<endl;
    return curBal;//return balance after calculations
}
void ptStruc(Account *point){
    int width=28;//width for formatting output
    cout<<"Account info for "<<point->name<<endl;
    cout<<left<<setw(width)<<"Name :"<<point->name<<endl;
    cout<<left<<setw(width)<<"Address :"<<point->address<<endl;
    cout<<left<<setw(width)<<"Account number:"<<point->acctNum<<endl;
    cout<<left<<setw(width)<<"Balance at start of month "<<"$"<<point->begBal
            <<endl;
    cout<<left<<setw(width)<<"Total written in checks :"<<"$"<<point->totChck
            <<endl;
    cout<<left<<setw(width)<<"Total deposited :"<<"$"<<point->totDeps<<endl;
    cout<<left<<setw(width)<<"Your current balance is :"<<"$"<<point->endBal
            <<endl;
}
void cleanUp(Account *point){
    delete point;
}