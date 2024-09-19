 #ifndef StudentTestScores_h
#define StudentTestScores_h

#include <string>
using namespace std;
//usually:
//no using namespace std; in .h files (namespace pollution)

class StudentTestScores
{
private:
    string name;
    double* testScores;
    int numTestScores;
    
public:
    //Constructor:
    StudentTestScores(string n, int size, double initScore);
    
    //Destructor:
    ~StudentTestScores();
    
    //Copy constructor:
    StudentTestScores(const StudentTestScores& obj);
    
    //Assignment operator:
    StudentTestScores& operator=(const StudentTestScores& obj);
    
    //Accessor function:
    void printScores() const;
    //NAME: setScore
    //INPUT: integer for index in array, double for value to be inserted
    //OUTPUT: index if valid insertion, -1 if otherwise
    //DESCRIPTION: checks if index is valid; if not, return -1;
    //else, insert score and return index to indicate valid insertion
    int setScore(int index, double value);
};

#endif
