/* 
 * File:   Car.h
 * Author: John Haller
 *
 * Created on November 5, 2018, 5:11 PM
 */
using namespace std;
#include <string>

#ifndef CAR_H
#define CAR_H

class Car{
private:
    int yearMdl;
    string make;
    int speed;
public:
    Car(int,string);
    int getMdl()const;
    string getMake()const;
    int getSped()const;
    void acclrte();
    void brake();
};

#endif /* CAR_H */

