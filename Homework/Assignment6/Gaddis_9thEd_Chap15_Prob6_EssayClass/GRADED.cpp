/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "GRADED.h"

char Graded::LtrGrade() const{
    char letter;
    if(score>89)letter='A';
    else if(score>79)letter='B';
    else if(score>69)letter='C';
    else if(score>59)letter='D';
    else letter='F';
    return letter;
}