#include "StudentTestScores.h"
#include <iostream>
using namespace std;

//Constructor:
StudentTestScores::StudentTestScores(string n, int size, double initScore)
{
    numTestScores = size;
    testScores = new double[numTestScores];
    //dynamically allocate an array above.
    name = n;
    for (int i = 0; i < size; i++) 
    {
        testScores[i] = initScore;
    }//close for loop.
}//close constructor.

//Destructor:
StudentTestScores::~StudentTestScores() 
{
    delete[] testScores;
}

//Copy constructor
StudentTestScores::StudentTestScores(const StudentTestScores& obj)
{
    numTestScores = obj.numTestScores;//Get the size of the array
    testScores = new double[numTestScores];//Allocate new array
    name = obj.name;
    //Copy array values
    for (int i = 0; i < numTestScores; i++) 
    {
        testScores[i] = obj.testScores[i];
    }//close for loop.
}//close copy constructor.

//Assignment operator:
StudentTestScores& StudentTestScores::operator=(const StudentTestScores& obj)
{
    if (&obj == this)//Checking for aliasing.
    {
        return *this;
    }//end if.
    
    delete[] testScores;//Destroy old dynamically allocated array.
    name = obj.name;
    numTestScores = obj.numTestScores;
    testScores = new double[numTestScores];
    //Copy array values
    for (int i = 0; i < numTestScores; i++) 
    {
        testScores[i] = obj.testScores[i];
    }//close for loop.
    return *this;
}//close assignment operator:

//member func: prints scores for particular student.
void StudentTestScores::printScores() const
{
    cout << "These are the scores for " << name << endl;
    for (int i = 0; i < numTestScores; i++) 
    {
        cout << "score" << (i + 1) << ": " << testScores[i] << endl;
    }//close for loop.
    cout << endl;
}//close member function.

//member function: checks if index is valid; if not, return -1;
//else, insert score and return index to indicate valid insertion
int StudentTestScores::setScore(int index, double value)
{
    if (index < 0 || index >= numTestScores) 
        //Checks if we are outside the array bounds in condition.
    {
        return -1;
    }
    else
    {
        testScores[index] = value;
        return index;
    }
}//close member function.
