/* 
 * File:   RetailItem.h
 * Author: John Haller
 *
 * Created on November 5, 2018, 5:59 PM
 */

#include <string>
using namespace std;

#ifndef RETAILITEM_H
#define RETAILITEM_H

class Invntry{
private:
    string descrpt;
    int units;
    float price;
public:
    Invntry(string,int,float);
    string getDesc()const;
    int getUnit()const;
    float getPrce()const;
};

#endif /* RETAILITEM_H */

