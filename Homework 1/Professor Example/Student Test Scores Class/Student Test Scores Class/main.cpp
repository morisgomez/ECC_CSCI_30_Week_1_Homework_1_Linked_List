#include "StudentTestScores.h"

int main()
{
    StudentTestScores s1("John", 3, 80);
    s1.printScores();//print scores.
    StudentTestScores s2 = s1;//calls copy constructor
    StudentTestScores s3(s2);//calls copy constructor
    s1.setScore(2, 100);
    s1.setScore(0, 70);
    s1 = s1;// example of aliasing
    s3 = s1;//calls assignment operator
    s1.printScores();//print scores.
    s2.printScores();//print scores.
    s3.printScores();//print scores.

    return 0;
}//destructor called for s1, s2, and s3
