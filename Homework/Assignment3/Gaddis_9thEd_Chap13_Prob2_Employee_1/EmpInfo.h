/* 
 * File:   PerInfo.h
 * Author: John Haller
 *
 * Created on November 5, 2018, 3:55 PM
 */
using namespace std;
#include <string>
#include <iostream>

#ifndef PERINFO_H
#define PERINFO_H


class INFO{
private: 
    string name;
    int idNum;
    string dept;
    string pos;
public:
    INFO(string,int,string,string);
    INFO(string,int);
    INFO();
    void setName();
    void setID();
    void setDept();
    void setPos();
    string getName() const;
    int getID() const;
    string getDept() const;
    string getPos() const;
};


#endif /* PERINFO_H */

