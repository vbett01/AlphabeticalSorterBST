//
//  mainTester.cpp
//  hw4
//
//  Created by Vincent Bett on 10/27/16.


/*
A Tester file for the binary search tree.
It calls the functions in the tree and tests them.
*/

#include <stdio.h>
#include <iostream>
#include "StringBST.h"
#include "Alphabetizer.h"
using namespace std;


int main()
{
	// create new array
	const int cap = 7;
	string arr[cap];

	Alphabetizer add;
	StringBST newTree;

	// Poppulate the array
	arr[0] = "Bison";
	arr[1] = "Deer";
	arr[2] = "Kingfisher";
	arr[3] = "Llama";
	arr[4] = "Ram";
	arr[5] = "Swan";
	arr[6] = "Horse";
	// add values to the tree
	StringBST tree(arr, cap);

	// Print items an empty tree.
	newTree.print();

	// Print items in the tree.
	tree.print();

	// add an element to the tree
	tree.add("vincent");
	// remove an element
	tree.remove("Ram");

	//Check if it contains
	if(tree.contains("Deer"))
	{
		cout<<"It has a deer"<<endl;
	}
	// remove the minimum
	tree.removeMin();

	// Print the size of the tree
	cout <<"the size of the tree is "<<tree.size()<<endl;

	// remove the max element.
	tree.removeMax();

	//print the min
	cout<<tree.getMin()<<endl;




	return 0;
}
