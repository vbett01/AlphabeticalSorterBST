//
//  StringBST.hpp
//  hw4
//
//  Created by Vincent Bett on 10/22/16.

/*
Header file for the binary search tree class.
It implements an BST of strings and stores them from smallest to
largest.
*/

#ifndef StringBST_h
#define StringBST_h

#include <stdio.h>
#include <iostream>
#include <stdexcept>
using namespace std;

struct BSTNode{
    string value;
    BSTNode *left;
    BSTNode *right;
    int instances;
};

class StringBST
{
public:
    
    
    StringBST();
    StringBST(string array[], int n);
    ~StringBST();
    /*
     FUNCTION: isEmpty
     PURPOSE: function that takes no parameters and returns a
     boolean value that is true if this specific instance of the
     StringBST class is empty and false otherwise
     INPUT: None
     OUTPUT:None
    */
    bool isEmpty();
    /*
     FUNCTION: clear
     PURPOSE: function that takes no parameters and has a void
     return type.  It makes the current binary search tree into
     an empty binary search tree.
     INPUT: None
     OUTPUT: None
    */
    void clear();
    /*
     FUNCTION: size.
     PURPOSE: function that takes no parameters and returns an
     integer value that is the number of strings in the binary
     search tree.
     INPUT: None
     OUTPUT: None
     */
    int size();
    /*
     FUNCTION: print
     PURPOSE: function that takes no parameters and returns nothing.
     It prints the binary search tree in order.
     INPUT: None
     OUTPUT: None
     */
    void print();
    /*
     FUNCTION: add
     PURPOSE: function that takes an element (string) and adds it to
     the binary search tree in the correct location based on the
     behavior of binary search trees.
     INPUT: a string
     OUTPUT: None
     */
    void add(string element);
    /*
     FUNCTION: remove
     PURPOSE:function that takes a target (string) as a parameter
     and returns a boolean.  It will find the target and then proceed
     to remove one instance of it from the tree.  The boolean
     returned reflects whether or not the function was able to find
     and remove the target.
     INPUT: A string
     OUTPUT: None
     */
    bool remove(string element);
    /*
     FUNCTION: getMin
     PURPOSE: function that takes no parameters and returns a
     string.  It returns the left most (smallest) string in the
     binary search tree.  If the tree is empty it throws a C++
     "runtime_error" exception
     INPUT: a string
     OUTPUT: None
     */
    string getMin();
    /*
     FUNCTION: getMax
     PURPOSE:function that takes no parameters and returns a
     string.  It returns the right most (largest) string in the
     binary search tree.  If the tree is empty it throws a C++
     "runtime_error" exception
     INPUT: None
     OUTPUT: None
     */
    string getMax();
    /*
     FUNCTION: removeMin
     PURPOSE: function that takes no parameters and returns
     nothing (not a boolean).  It removes and returns the left most
     (smallest) string in the binary search tree.
     INPUT: None
     OUTPUT: None
     */
    void removeMin();
    /*
     FUNCTION:removeMax
     PURPOSE: function that takes no parameters and returns
     nothing (not a boolean).  It removes and returns the right most
     (largest) string in the binary search tree.
     INPUT: None
     OUTPUT: None
     */
    void removeMax();
    /*
     FUNCTION: contains
     PURPOSE: function that takes a string as a parameter, and
     returns a boolean.  It will search the binary search tree, and
     if it finds the query returns true, otherwise it will return
     false.
     INPUT: None
     OUTPUT: None
     */
    bool contains(string element);
private:
    
        BSTNode *root; // Store address of root
    
    /*
     FUNCTION: getMinimumPtr
     PURPOSE: To return the pointer to the minimum value in the tree
     INPUT: A pointer to a node
     OUTPUT: A pointer to a node.
     */
    BSTNode* getMinimumPtr(BSTNode* node);
    
    /*
     FUNCTION: MakeNewNode
     PURPOSE: To make a new node that will be added to the tree
     INPUT: a string
     OUTPUT: a pointer to a node
     */
    BSTNode* MakeNewNode(string element);
    
    /*
     FUNCTION: insertNewElement
     PURPOSE: To insert an element into the tree.
     INPUT: a pointer to a node and a string
     OUTPUT: a pointer to a node.
     */
    BSTNode* insertNewElement(BSTNode* node, string elem);
    
    /*
     FUNCTION: Search
     PURPOSE: To searcht the treee for an element
     INPUT: a pointer to a node and a string
     OUTPUT: A bool
     */
    bool search(BSTNode* node, string elem);
    
    /*
     FUNCTION: Delete
     PURPOSE: To remove a node from the tree
     INPUT: a pointer to a node and a string
     OUTPUT: None
     */
    BSTNode* Delete(BSTNode* node, string elem);
    
    /*
     FUNCTION: findMin
     PURPOSE: To find the minimum element in the tree.
     INPUT: a pointer to a node
     OUTPUT: a string.
     */
    string findMin(BSTNode* node);
    
    /*
     FUNCTION: findMax
     PURPOSE: To find the max value in a tree
     INPUT: a pointer to a node.
     OUTPUT: A string
     */
    string findMax(BSTNode* node);
    
    /*
     FUNCTION: PostOrderDelete
     PURPOSE: To delete the tree using post order.
     INPUT: a pointer
     OUTPUT: none
     */
    void PostOrderDelete(BSTNode* node);
    
    /*
     FUNCTION: Count
     PURPOSE: To count the number of elements in the tree
     INPUT: a Pointer to a node
     OUTPUT: an int
     */
    int Count(BSTNode* node);
    
    /*
     FUNCTION: FoundToDelete
     PURPOSE: To delete the node that we have found
     INPUT: a pointer to a node
     OUTPUT: a pointer to a node
     */
    BSTNode* FoundToDelete(BSTNode* node);
    
    /*
     FUNCTION: inOrderPrint
     PURPOSE: To print the tree in order
     INPUT: a pointer to a node
     OUTPUT: none
     */
    void inOrderPrint(BSTNode* node);
    
};
#endif /* StringBST_hpp */
