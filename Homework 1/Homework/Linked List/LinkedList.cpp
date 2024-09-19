#include "LinkedList.h"
#include <iostream>
//Node constructor:
Node::Node()
{
    value = "default";
    next = NULL;
}

//LinkedList constructor:
LinkedList::LinkedList()
{
    head = NULL;
}

//LinkedList copy constructor:
LinkedList::LinkedList(const LinkedList& rhs)
{
    if(rhs.head == NULL)
    {
        head = rhs.head;
    }
    else
    {
        Node *temp = rhs.head;
        Node *n = new Node;
        n->value = temp->value;
        head = n;
        temp = temp->next;
        while(temp != NULL)
        {
            Node *x = new Node;
            n->next = x;
            n = x;
            x->value = temp->value;
            temp = temp->next;
        }
    }
}

//LinkedList destructor:
LinkedList::~LinkedList()
{
    Node *remove;
    remove = head;
    while(remove != NULL)
    {
        Node *n = remove->next;
        remove = n;
        delete remove;
    }
    std::cout << "destructor called" << std::endl;
}

//LinkedList assignment operator:
const LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
    if(&rhs == this)
    {
        return *this;
    }
    else
    {
        Node *remove;
        remove = head;
        while(remove != NULL)
        {
            Node *n = remove->next;
            delete remove;
            remove = n;
        }
        if(rhs.head == NULL)
        {
            head = rhs.head;
        }
        else
        {
            Node *temp = rhs.head;
            Node *n = new Node;
            n->value = temp->value;
            head = n;
            temp = temp->next;
            while(temp != NULL)
            {
                Node *x = new Node;
                n->next = x;
                n = x;
                x->value = temp->value;
                temp = temp->next;
            }
        }
    }
    return *this;
}

//LinkedList insertToFront() function:
void LinkedList::insertToFront(const ItemType &val)
{
    Node *n = new Node();
    n->value = val;
    n->next = NULL;
    if(head == NULL)
    {
        head = n;
    }
    else if(head != NULL)
    {
        n->next = head;
        head = n;
    }
}

//LinkedList printList() function:
void LinkedList::printList() const
{
    Node *current = head;
    while(current != NULL)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

//LinkedList get() function:
bool LinkedList::get(int i, ItemType& item) const
{
    bool flag = false;
    Node *current = head;
    int counter = 0;
    while(current != NULL)
    {
        if(counter == i)
        {
            item = current->value;
            flag = true;
            break;
        }
        else
        {
            current = current->next;
            counter = counter + 1;
            flag = false;
        }
    }
    return flag;
}

//LinkedList reverseList() function:
void LinkedList::reverseList()
{
    Node *previous = NULL;
    Node *current = head;
    Node *nexT = NULL;
    while(current != NULL)
    {
        nexT = current->next;
        current->next = previous;
        previous = current;
        current = nexT;
    }
    head = previous;
}

//LinkedList printReverse() function:
void LinkedList::printReverse() const
{
    Node *current = head;
    while(current != NULL)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

//LinkedList append() function:
void LinkedList::append(const LinkedList &other)
{
    Node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    int size = other.size();
    Node* currentOther = other.head;
    for (int i = 0; i < size; i++)
    {
        Node* n = new Node;
        n->next = NULL;
        n->value = currentOther->value;
        current->next = n;
        current = current->next;
        currentOther = currentOther->next;
    }
}
          
//LinkedList swap() function:
void LinkedList::swap(LinkedList &other)
{
    Node *n = head;
    head = other.head;
    other.head = n;
    n = NULL;
}

//LinkedList size() function:
int LinkedList::size() const
{
    Node *current = head;
    int counter = 0;
    while(current != NULL)
    {
        counter = counter + 1;
        current = current->next;
    }
    return counter;
}
