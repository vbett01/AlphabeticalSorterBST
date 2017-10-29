//
//  AlphaTesting.cpp
//  hw4
//
//  Created by Vincent Bett on 10/27/16.


/*
 File that tests the alphabetizer class.
 It either accept user input interactively or 
 accepts a filename and a method from the command prompt.
*/

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include "StringBST.h"
#include "Alphabetizer.h"
using namespace std;

Alphabetizer test;
int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        test.run();
    }
    else if (argc == 2)
    {
        cerr<<"Not enough arguments"<<endl;
        return -1;
    }
    else
    {
        string Filename = argv[2];
        string order = argv[1];
        test.run(Filename, order);
    }
    
    
    return 0;
}
