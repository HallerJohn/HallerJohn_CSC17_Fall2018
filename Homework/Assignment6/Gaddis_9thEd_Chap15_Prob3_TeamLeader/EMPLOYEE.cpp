/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "EMPLOYEE.h"
#include <iostream>
using namespace std;


Emplyee::Emplyee(){
    cout<<"Enter employee name"<<endl;
    setName();
    cout<<"Enter employee number"<<endl;
    setNumb();
    cout<<"Enter hire date [mm/dd/yy]"<<endl;
    setDate();
}