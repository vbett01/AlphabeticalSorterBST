//
//  Alphabetizer.hpp
//  hw4
//
//  Created by Vincent Bett on 10/27/16.

/*
Header file for the alphabetizer class.
It uses the BST class to sort strings.
*/

#ifndef Alphabetizer_h
#define Alphabetizer_h

#include <stdio.h>
#include <iostream>
#include <fstream>

#include "StringBST.h"

using namespace std;

class Alphabetizer
{
public:
    // Constructor.
    Alphabetizer();
    // Destructor.
    ~Alphabetizer();
    
    /*
     FUNCTION: Run
     PURPOSE: To read in the commands from the command prompt
     INPUT: None
     OUTPUT: None
     */
    void run();
    
    /*
     FUNCTION: Run
     PURPOSE: To read in values from a file an arrange them  accoring to the
     specified order.
     INPUT: None
     OUTPUT: None
     */
    void run(string Filename, string order);
    
    
    
private:
    StringBST tree;
    
    /*
     FUNCTION: printFunction
     PURPOSE: To determine which order the tree will be printed
     INPUT: two strings
     OUTPUT: None
     */
    void printFunction(int input, string from);
    
    /*
     FUNCTION: printInreverse
     PURPOSE: To prinnt the tree from highest to lowest
     INPUT: two strings
     OUTPUT: none
     */
    void printInreverse(string input, string from);
    
    /*
     FUNCTION: printInOrder
     PURPOSE: To print the tree from lowes to highest value
     INPUT: Two strings
     OUTPUT: None
     */
    void printInOrder(string input, string from);
    
    /*
     FUNCTION: getStrings
     PURPOSE: To get the strings from the file
     INPUT: A pointer to a file location
     OUTPUT: none
     */
    void getStrings(istream &infile);
    
   
};

#endif /* Alphabetizer_h */
