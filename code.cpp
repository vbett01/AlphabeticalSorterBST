#include <iostream>
#include <csignal>
#include <csetjmp>

#include "StringBST.h"


// To catch the segfaults in student's codes
jmp_buf jBuffer;

// Test Big 3 relies on nothing
bool testBig3()
{
    StringBST test;
    return true;
}

// Test isEmpty relies on a good default constructor
bool testIsEmpty()
{
    StringBST test1;
    return test1.isEmpty() == true;
}

// Test Size relies on good constructors
bool testSize()
{
    bool allPassed = true;
    StringBST test1;
    std::string array1[4] = {"aa","bb","cc","dd"};
    std::string array2[3] = {"z","m","a"};
    StringBST test2(array1,4);
    StringBST test3(array2,3);
    allPassed &= (test1.size() == 0);
    allPassed &= (test2.size() == 4);
    allPassed &= (test3.size() == 3);
    return allPassed;
}

// Test Clear relies on a good isEmpty and constructors
bool testClear()
{
    bool allPassed = true;
    StringBST test1;
    std::string array[4] = {"a","m","c","v"};
    StringBST test2(array,4);
    test1.clear();
    test2.clear();
    allPassed &= test1.isEmpty();
    allPassed &= test2.isEmpty();
    return allPassed;
}

// TestPrint relies on good constructors
bool testPrint()
{
    StringBST test1;
    std::string array[4] = {"a","m","c","v"};
    StringBST test2(array,4);
    test1.print();
    std::cout << std::endl;
    test2.print(); 
    std::cout << std::endl;
    return true;
}

// TestAdd relies on good constructors and prints
bool testAdd()
{
    StringBST test1;
    test1.add("a");
    test1.print();
    std::cout << std::endl;
    test1.add("m");
    test1.print();
    std::cout << std::endl;
    test1.add("v");
    test1.print();
    std::cout << std::endl;
    test1.add("d");
    test1.print();
    std::cout << std::endl;
    test1.add("u");
    test1.print();
    std::cout << std::endl;
    test1.add("h");
    test1.print();
    std::cout << std::endl;
    test1.add("e");
    test1.print();
    std::cout << std::endl;
    test1.add("q");
    test1.print();
    std::cout << std::endl;
    return true;
}

// TestRemove relies on good constructors and prints
bool testRemove()
{
    std::string array[4] = {"a","m","q","d"};
    StringBST test1(array,4);
    test1.print();
    std::cout << std::endl;
    test1.remove("d");
    test1.print();
    std::cout << std::endl;
    test1.remove("a");
    test1.print();
    std::cout << std::endl;
    test1.remove("m");
    test1.print();
    std::cout << std::endl;
    return test1.remove("m") == false;
}

// TestContains relies on good constructors
bool testContains()
{
    bool allPassed = true;
    std::string array[4] = {"a","b","c","!"};
    StringBST test1(array,4);
    allPassed &= test1.contains("a");
    allPassed &= test1.contains("b");
    allPassed &= test1.contains("d") == false;
    allPassed &= test1.contains("!");
    return allPassed;
}



void sighandler(int signum)
{
    longjmp(jBuffer,signum);
}

void runTests(int numTests , std::string names[] , bool (*tests[])())
{
    bool allPassed = true;
    for(int test = 0; test < numTests; test++)
    {   
        try
        {
            // Start segfault signal buffer
            signal(SIGSEGV,sighandler);

            // Jumps to here in case of an access violation
            int sig;
            sig = setjmp(jBuffer);
            if(sig == 0)
            {
                bool result = tests[test]();
                std::string resultStr = result ? " passed" : " failed";
                std::cout << "Test " << names[test] << resultStr << std::endl;
            }
            else
            {
                std::cout << "Segfault in test" << names[test] << std::endl;
                throw -1;
            }
        }
        catch(...)
        {
            std::cout << "continuing..." << std::endl;
            allPassed = false;
        }
    }
    if(allPassed)
    {
        std::cout << "All tests passed!" << std::endl;
    }
}

int main()
{
    int numTests = 8;
    std::string testNames[10] =
    {
        "big3",
        "isEmpty",
        "size",
        "clear",
        "print",
        "add",
        "remove",
        "contains"
    };
    bool (*tests[10])() =
    {
        testBig3,
        testIsEmpty,
        testSize,
        testClear,
        testPrint,
        testAdd,
        testRemove,
        testContains
    };

    runTests(numTests,testNames,tests);
}
