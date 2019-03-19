/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PROB1.h
 * Author: John Haller
 *
 * Created on December 12, 2018, 2:30 PM
 */

#ifndef PROB1_H
#define PROB1_H

class Prob1Random
{
	private:
		char *set;      //The set of numbers to draw random numbers from
		char  nset;     //The number of variables in the sequence
		int  *freq;     //Frequency of all the random numbers returned
		int   numRand;  //The total number of times the random number function is called
	public:
		Prob1Random(const char,const char *);     //Constructor
		~Prob1Random(void);                       //Destructor
		char randFromSet(void);                   //Returns a random number from the set
		int *getFreq(void) const;                 //Returns the frequency histogram
		char *getSet(void) const;                 //Returns the set used
		int getNumRand(void) const;               //Gets the number of times randFromSet has
		                                          //been called
};

#endif /* PROB1_H */

