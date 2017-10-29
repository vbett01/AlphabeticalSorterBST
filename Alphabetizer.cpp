//
//  Alphabetizer.cpp
//  hw4
//
//  Created by Vincent Bett on 10/27/16.

/*
File to implement the alphabetizer.
It uses the binary search tree to 
order strings in an alphabetical order
or revers order.
It also accepts user input.
*/

#include "Alphabetizer.h"

// Constructor.
Alphabetizer::Alphabetizer()
{

}

// Destructor.
Alphabetizer::~Alphabetizer()
{

}

/*
FUNCTION: Run
PURPOSE: To read in the commands from the command prompt
and execute those commands. It also checks if the user input
is valid.
INPUT: None
OUTPUT: None
*/
void Alphabetizer::run()
{

    
    string input;
    int count = 0;
    int method = 0;
    while(cin>> input)
    {
        if(input == "f" and count == 0)
        {
            method = 1;
        }
        else if(input == "r" and count == 0)
        {
            method = 2;
        }
        else if(count == 0 and (input != "f" or input != "r"))
        {
        cerr<<"Usage: alphabetizer [order filename]"<<endl;
        }
        else
        {
            tree.add(input);
        }
        count++;
    }
    string from = "cin";
    printFunction(method, from);

}


/*
FUNCTION: Run
PURPOSE: To read in values from a file an arrange them  accoring to the
specified order.
INPUT: None
OUTPUT: None
*/
void Alphabetizer::run(string Filename, string order)
{
    int method;
	ifstream input;
	input.open(Filename);
	if (not input.is_open()) {
		cerr << "Unable to open " << Filename << endl;
        return;        
	}
	getStrings(input);
    if(order == "f")
    {
        method = 1;
    }
    if(order == "r")
    {
        method = 2;
    }
	printFunction(method, Filename);
}

/*
FUNCTION: getStrings
PURPOSE: To get the strings from the file
INPUT: A pointer to a file location
OUTPUT: none
*/
void Alphabetizer::getStrings(istream &infile)
{
	string s;
	for (infile >> s; not infile.eof(); infile >> s)
	{
		tree.add(s);
	}

}

/*
FUNCTION: printFunction
PURPOSE: To determine which order the tree will be printed
INPUT: two strings
OUTPUT: None
*/
void Alphabetizer::printFunction(int method, string from)
{
    string input;
	if(method == 2)
	{
         input = "r";
		printInreverse(input, from);
	}
	else if(method == 1)
	{
        input = "f";
		printInOrder(input, from);
	}
}

/*
FUNCTION: printInreverse
PURPOSE: To prinnt the tree from highest to lowest
INPUT: two strings
OUTPUT: none
*/
void Alphabetizer::printInreverse(string input, string from)
{
	cout<<"[";
	cout<<from<<", "<< input<<" : ";
	string min = tree.getMin();
	tree.removeMin();
	while(!tree.isEmpty())
	{

		cout<<tree.getMax()<<", ";
		tree.removeMax();
	}
	cout<<min;
	cout<<" ]"<<endl;
}

/*
FUNCTION: printInOrder
PURPOSE: To print the tree from lowes to highest value
INPUT: Two strings
OUTPUT: None
*/
void Alphabetizer::printInOrder(string input, string from)
{
	cout<<"[";
	cout<<from<<", "<< input<<" : ";
	string max = tree.getMax();
	tree.removeMax();
	while(!tree.isEmpty())
	{

		cout<<tree.getMin()<<", ";
		tree.removeMin();

	}
	cout<<max;
	cout<<" ]"<<endl;

}
