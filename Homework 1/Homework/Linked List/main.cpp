#include "LinkedList.h"
#include <iostream>
int main()
{
    //1)testing insertToFront(), size() & get() functions:
    //PASSED.
    LinkedList ListOne;
    ListOne.insertToFront("Hawkeye");
    ListOne.insertToFront("Thor");
    ListOne.insertToFront("Hulk");
    ListOne.insertToFront("Black Widow");
    ListOne.insertToFront("Iron Man");
    ListOne.insertToFront("Captain America");
    for (int k = 0; k < ListOne.size(); k++)
    {
    ItemType x;
    ListOne.get(k, x);
    std::cout << x << std::endl;
    }
    
    //2)testing printList(), reverseList() & printReverse() functions:
    //PASSED.
    LinkedList ListTwo;
    ListTwo.insertToFront("The Mandalorian");
    ListTwo.insertToFront("Baby Yoda");
    ListTwo.insertToFront("Cara Dune");
    ListTwo.insertToFront("Greef Karga");
    ListTwo.printList();
    ListTwo.reverseList();
    ListTwo.printReverse();
    std::cout << "---" << std::endl;
    
    //3)testing swap() function:
    //PASSED.
    ListOne.printList(); //Captain America Iron...
    ListTwo.printList(); //The Mandalorian Baby...
    std::cout << "---" << std::endl;
    ListOne.swap(ListTwo);
    ListOne.printList(); //The Mandalorian Baby...
    ListTwo.printList(); //Captain America Iron...
    std::cout << "---" << std::endl;
    
    //4)testing copy constructor:
    //PASSED.
    LinkedList ListThree = ListTwo;
    ListTwo.printList(); //Captain America Iron...
    ListThree.printList(); //Captain America Iron...
    std::cout << "---" << std::endl;
    
    //5)testing assigment operator:
    //PASSED.
    LinkedList ListFour;
    ListFour.insertToFront("Footprint");
    ListFour.insertToFront("Handbook");
    ListFour.insertToFront("Chile");
    ListFour.printList(); //Chile Handbook Footprint
    ListThree = ListFour;
    std::cout << "---" << std::endl;
    ListThree.printList(); //Chile Handbook Footprint
    ListFour.printList(); //Chile Handbook Footprint
    
    //6)testing append() function:
    //PASSED.
    LinkedList ListNine;
    ListNine.insertToFront("fluffy");
    ListNine.insertToFront("holidays");
    ListNine.insertToFront("happy");
    ListNine.printList();
    
    LinkedList ListTen;
    ListTen.insertToFront("cute");
    ListTen.insertToFront("super");
    ListTen.insertToFront("youre");
    ListTen.printList();
    
    ListNine.append(ListTen);
    ListNine.printList();
    std::cout << "---" << std::endl;
    
    //7)testing destructor:
    //PASSED?
    //*automatically called at end of program*
    //*explicit call produces error though*
    //ListONe.~LinkedList();
    
    return 0;
}
