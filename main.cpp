//
//  main.cpp
//  hw4
//
//  Created by Vincent Bett on 10/22/16.

/*
 Main file that is used to accept user input
 and to call both the alphabetizer and StringBST
*/

#include <iostream>
#include "Alphabetizer.h"
using namespace std;

Alphabetizer sort;
int main(int argc, const char* argv[]) {
    
    if (argc == 1)
    {
         sort.run();
    }
    else if (argc < 3 or argc > 3)
    {
        cerr<<"Usage: alphabetizer [order filename]"<<endl;
        return 1;
    }
    else
    {
        string Filename = argv[2];
        string order = argv[1];
        
        if(order != "f" and order != "r")
        {
                cerr<<"Usage: alphabetizer [order filename]"<<endl;
                return 1;
        }
        
        sort.run(Filename, order);
    }
    
   
    return 0;
}
