#ifndef LinkedList_h
#define LinkedList_h
#include <string>
#include <stdio.h>


struct listElement{
    std::string name;
    listElement* next;
    listElement* previous;
};


class LinkedList
{

    public:
        LinkedList(bool circular, bool doubly);
        virtual ~LinkedList();
        void addElement(std::string next, std::string name);
        void removeElement(std::string name);
        void printList();
        void getElementDetails(std::string name);
    protected:
    private:
      listElement* head;
      listElement* tail;
      bool isCircularlyLinked;
      bool isDoublyLinked;
};


#endif
