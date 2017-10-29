//
//  StringBST.cpp
//  hw4
//
//  Created by Vincent Bett on 10/22/16.

/*
Class implementation of the binary search tree header file
It implements a binary search tree of strings.
*/

#include "StringBST.h"
// Constructor
StringBST::StringBST()
{
	root = NULL;

}

/*
   The second constructor takes an array of strings and an
   integer specifying the size of the array as parameters and
   creates a binary search tree with strings inserted in the
   order in which they appear in the array.
 */
StringBST::StringBST(string array[], int n)
{
	root = NULL;
	for(int i = 0; i<n; i++)
	{
		add(array[i]);
	}
}

// Destructor
StringBST::~StringBST()
{
	PostOrderDelete(root);
}
/*
FUNCTION: MakeNewNode
PURPOSE: To make a new node that will be added to the tree
INPUT: a string
OUTPUT: a pointer to a node
 */
BSTNode* StringBST::MakeNewNode(string element)
{
	BSTNode* newNode = new BSTNode();
	newNode->value = element;
	newNode->left = newNode->right = NULL;
	newNode->instances = 1;
	return newNode;

}

/*
FUNCTION: isEmpty
PURPOSE: function that takes no parameters and returns a
boolean value that is true if this specific instance of the
StringBST class is empty and false otherwise
INPUT: None
OUTPUT:None
*/
bool StringBST::isEmpty()
{
	return root == NULL;
}


/*
FUNCTION: clear
PURPOSE: function that takes no parameters and has a void
return type.  It makes the current binary search tree into
an empty binary search tree.
INPUT: None
OUTPUT: None
*/
void StringBST::clear()
{
	PostOrderDelete(root);
        root = NULL;
}

/*
FUNCTION: PostOrderDelete
PURPOSE: To delete the tree using post order.
INPUT: a pointer
OUTPUT: none
*/
void StringBST::PostOrderDelete(BSTNode* node)
{
	if(node == NULL)
        {
                return;
        }
        if(node->left != NULL)
        {
                PostOrderDelete(node->left);
        }
        if(node->right != NULL)
        {
                PostOrderDelete(node->right);
        }
        delete node;
}
/*
FUNCTION: size.
PURPOSE: function that takes no parameters and returns an
integer value that is the number of strings in the binary
search tree.
INPUT: None
OUTPUT: None
*/
int StringBST::size()
{
	return Count(root);
}

/*
FUNCTION: Count
PURPOSE: To count the number of elements in the tree
INPUT: a Pointer to a node
OUTPUT: an int
*/
int StringBST::Count(BSTNode* node)
{
	if(node == NULL)
        {
                return 0;
        }
        else
        {
         return node->instances + Count(node->left) + Count(node->right);
        }

}
/*
FUNCTION: print
PURPOSE: function that takes no parameters and returns nothing.
It prints the binary search tree in order.
INPUT: None
OUTPUT: None
*/
void StringBST::print()
{
	inOrderPrint(root);

}

/*
FUNCTION: inOrderPrint
PURPOSE: To print the tree in order
INPUT: a pointer to a node
OUTPUT: none
*/
void StringBST::inOrderPrint(BSTNode* node)
{
	cout<<"[";   
	if(node != NULL)
	{

		inOrderPrint(node->left);
                cout<<" ";
		cout<<node->value <<" ";
		cout<<node->instances;
                cout<<" ";
		inOrderPrint(node->right);

	}
	cout<<"]";
}

/*
FUNCTION: add
PURPOSE: function that takes an element (string) and adds it to
the binary search tree in the correct location based on the
behavior of binary search trees.
INPUT: a string
OUTPUT: None
*/
void StringBST::add(string element)
{

	root = insertNewElement(root, element);

}

/*
FUNCTION: insertNewElement
PURPOSE: To insert an element into the tree.
INPUT: a pointer to a node and a string
OUTPUT: a pointer to a node.
*/
BSTNode* StringBST::insertNewElement(BSTNode* node, string elem)
{
	if(node == NULL)
	{
		node = MakeNewNode(elem);
	}
	else if(elem < node->value)
	{
		node-> left =  insertNewElement(node->left, elem);
	}
	else if (elem > node->value)
	{
		node->right = insertNewElement(node->right, elem);
	}
	else
	{
		node->instances +=1;
	}
	return node;

}



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
bool StringBST::remove(string element)
{
	if(contains(element))
	{
		root = Delete(root, element);
		return true;
	}
	else
		return false;


}

/*
FUNCTION: Delete
PURPOSE: To remove a node from the tree
INPUT: a pointer to a node and a string
OUTPUT: None
*/
BSTNode* StringBST::Delete(BSTNode* node, string elem)
{
	if(node == NULL)
	{
		return  node;
	}
	else if(elem < node->value)
	{
		node->left = Delete(node->left, elem);
	}
	else if(elem > node->value)
	{
		node->right = Delete(node->right, elem);
	}
	else
	{
		node =  FoundToDelete(node);

	}
	return node;
}

/*
FUNCTION: FoundToDelete
PURPOSE: To delete the node that we have found
INPUT: a pointer to a node
OUTPUT: a pointer to a node
*/
BSTNode* StringBST::FoundToDelete(BSTNode* node)
{
	if(node->instances > 1)
	{
		node->instances -=1;
		return node;
	}
	else if(node->left == NULL and node->right == NULL)
	{
		delete node;
		node = NULL;
		return node;
	}
	else if(node->left == NULL)
	{
		BSTNode *temp = node;
		node = node->right;
		delete temp;
		return node;
	}
	else if(node->right == NULL)
	{
		BSTNode* temp = node;
		node = node->left;
		delete temp;
		return node;
	}
	else
	{
		BSTNode *temp = getMinimumPtr(node->right);
		node->value = temp->value;
		node->right = Delete(node->right, temp->value);
	}
	return node;
}


/*
FUNCTION: getMinimumPtr
PURPOSE: To return the pointer to the minimum value in the tree
INPUT: A pointer to a node
OUTPUT: A pointer to a node.
*/
BSTNode* StringBST::getMinimumPtr(BSTNode* node)
{
	while(node->left!= NULL)
	{
		node = node->left;
	}
	return node;
}

/*
FUNCTION: getMin
PURPOSE: function that takes no parameters and returns a
string.  It returns the left most (smallest) string in the
binary search tree.  If the tree is empty it throws a C++
"runtime_error" exception
INPUT: a string
OUTPUT: None
*/
string StringBST::getMin()
{
	return findMin(root);

}

/*
FUNCTION: findMin
PURPOSE: To find the minimum element in the tree.
INPUT: a pointer to a node
OUTPUT: a string.
*/
string StringBST::findMin(BSTNode* node)
{
	if(node == NULL)
	{
		// Throw an error
		throw runtime_error("getMin:empty_tree");
	}
	else if(node->left == NULL)
	{
		return node->value;
	}
	return findMin(node->left);
}

/*
FUNCTION: getMax
PURPOSE:function that takes no parameters and returns a
string.  It returns the right most (largest) string in the
binary search tree.  If the tree is empty it throws a C++
"runtime_error" exception
INPUT: None
OUTPUT: None
*/
string StringBST::getMax()
{

	return findMax(root);
}

/*
FUNCTION: findMax
PURPOSE: To find the max value in a tree
INPUT: a pointer to a node.
OUTPUT: A string
*/
string StringBST::findMax(BSTNode* node)
{

	if(node == NULL)
	{
		// Throw error.
		throw runtime_error("getMax:empty_tree");
	}
	else if(node->right == NULL)
	{
		return node->value;
	}
	return findMax(node->right);
}
/*
FUNCTION: removeMin
PURPOSE: function that takes no parameters and returns
nothing (not a boolean).  It removes and returns the left most
(smallest) string in the binary search tree.
INPUT: None
OUTPUT: None
*/
void StringBST::removeMin()
{

	string toRemove = findMin(root);
	root = Delete(root, toRemove);
}


/*
FUNCTION:removeMax
PURPOSE: function that takes no parameters and returns
nothing (not a boolean).  It removes and returns the right most
(largest) string in the binary search tree.
INPUT: None
OUTPUT: None
*/
void StringBST::removeMax()
{
	string toRemove = findMax(root);
	root = Delete(root, toRemove);

}

/*
FUNCTION: contains
PURPOSE: function that takes a string as a parameter, and
returns a boolean.  It will search the binary search tree, and
if it finds the query returns true, otherwise it will return
false.
INPUT: None
OUTPUT: None
*/
bool StringBST::contains(string element)
{
	return search(root, element);
}

/*
FUNCTION: Search
PURPOSE: To searcht the treee for an element
INPUT: a pointer to a node and a string
OUTPUT: A bool
*/
bool StringBST::search(BSTNode* node, string elem)
{
	if(node == NULL) return false;
	else if (node->value == elem) return true;
	else if(elem  <= node->value)
	{
		return search(node->left, elem);
	}
	else
	{
		return search(node->right, elem);
	}
}




