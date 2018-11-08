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
    string address;
    int age;
    string phneNum;
public:
    void setName();
    void setAddr();
    void setAge();
    void setPhne();
    string getName() const;
    string getAddr() const;
    int getAge() const;
    string getPhne() const;
};


#endif /* PERINFO_H */

