/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "SavingsAccount.h"
#include <iostream>
#include <cmath>
using namespace std;

SavingsAccount::SavingsAccount(float principal){
    if(principal>0)Balance=principal;
    else Balance = 0;
    FreqWithDraw=0;
    FreqDeposit=0;
}
void SavingsAccount::Transaction(float money){
    if(money>0)Deposit(money);
    else Withdraw(money);
}

void SavingsAccount::Deposit(float money){
    Balance+=money;
    FreqDeposit++;
}

void SavingsAccount::Withdraw(float money){
    money*=-1;
    if(Balance>money){
        Balance-=money;
        FreqWithDraw++;
    }
    if(money>Balance)cout<<"You cannot withdraw that much money"<<endl;
}

void SavingsAccount::toString(){
    cout<<"Your balance          = $"<<Balance<<endl;
    cout<<"Number of deposits    = "<<FreqDeposit<<endl;
    cout<<"Number of Withdrawels = "<<FreqWithDraw<<endl;
}

float SavingsAccount::Total(float savint, int time){
    return Balance*pow((1+savint),static_cast<float>(time));
}

float SavingsAccount::TotalRecursive(float savint, int time){
    return Balance*pow((1+savint),static_cast<float>(time));
}