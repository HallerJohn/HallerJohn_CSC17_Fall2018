/* 
 * File:   PerInfo.h
 * Author: John Haller
 *
 * Created on November 5, 2018, 3:55 PM
 */
#include <valarray>

#include "EmpInfo.h"



INFO::INFO(string Name,int ID,string Dept,string Pos){
    name=Name;
    idNum=ID;
    dept=Dept;
    pos=Pos;
}
INFO::INFO(string Name,int ID){
    name=Name;
    ID=idNum;
}
INFO::INFO(){
    name=" ";
    idNum=0;
    dept=" ";
    pos=" ";
}
void INFO::setName(){
    cout<<"Input employee name"<<endl;
    getline(cin,name);
}
void INFO::setID(){
    cout<<"Input employee ID"<<endl;
    cin>>idNum;
}
void INFO::setDept(){
    cout<<"Input department employee works in"<<endl;
    cin.ignore();
    getline(cin,dept);
}
void INFO::setPos(){
    cout<<"Input employee job title"<<endl;
    getline(cin,pos);
}
string INFO::getName() const{
    return name;
}
int INFO::getID() const{
    return idNum;
}
string INFO::getDept() const{
    return dept;
}
string INFO::getPos() const{
    return pos;
}