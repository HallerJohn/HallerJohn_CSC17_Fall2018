/* 
 * File:   PerInfo.h
 * Author: John Haller
 *
 * Created on November 5, 2018, 3:55 PM
 */
#include "PerInfo.h"


void INFO::setName(){
    cout<<"Input name"<<endl;
    getline(cin,name);
}
void INFO::setAddr(){
    cout<<"Input address"<<endl;
    getline(cin,address);
}
void INFO::setAge(){
    cout<<"Input age"<<endl;
    cin>>age;
}
void INFO::setPhne(){
    cout<<"Input phone number"<<endl;
    cin.ignore();
    getline(cin,phneNum);
}
string INFO::getName() const{
    return name;
}
string INFO::getAddr() const{
    return address;
}
int INFO::getAge() const{
    return age;
}
string INFO::getPhne() const{
    return phneNum;
}