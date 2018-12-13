/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SavingsAccount.h
 * Author: John Haller
 *
 * Created on December 12, 2018, 4:21 PM
 */

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount{
private:
    void Withdraw(float);               //Utility Procedure
    void Deposit(float);                //Utility Procedure
    float Balance;                       //Property
    int   FreqWithDraw;                  //Property
    int   FreqDeposit;                   //Property
public:
    SavingsAccount(float);               //Constructor
    void  Transaction(float);            //Procedure
    float Total(float,int);	         //Savings Procedure
    float TotalRecursive(float,int);
    void  toString();                    //Output Properties
};

#endif /* SAVINGSACCOUNT_H */

