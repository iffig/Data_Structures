#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

LinkedList::LinkedList(bool isCircular, bool isDoubly){
  listElement* head = NULL;
  listElement* tail = NULL;
  isCircularlyLinked = isCircular;
  isDoublyLinked = isDoubly;
}

LinkedList::~LinkedList(){

}

void LinkedList::addElement(string next, string name){
  listElement* x = head;
  if(head == NULL){
    listElement* temp = new listElement;
    head = temp;
    if(isCircularlyLinked) head->next = tail;
    else head->next = NULL;

    if(isDoublyLinked) head->previous = NULL;
    head->name = name;
    tail = head;
    temp = head;
  }
  else {
    listElement* n = new listElement;
    n-> name = name;

    while(x->next != NULL && x != tail){
        if(next == x->name){
            n->next = x->next;
            if(isDoublyLinked) n->previous = x;
            x->next = n;
        }
        x = x->next;
    }
    //If previous is last element in list or the previous is not specified...
    if(next == x->name || next == ""){
      tail = n;
        if(isCircularlyLinked){
          head->previous = n;
          n->next = head;
        }
        else n->next = NULL;
        if(isDoublyLinked) n->previous = x;
        x->next = n;
    }
  }
}


void LinkedList::removeElement(string name){
  listElement* x = head;
  listElement* temp = new listElement;

  // If only one element in list
  if(head == tail){
    temp = head;
    head = NULL;
    tail = NULL;
  }
  // If deleting head but its not the only element...
  if(x->name == name){
    temp = head;
    if(isCircularlyLinked){
      tail->next = temp->next;
      x->next->previous = tail;
    }
    else if(isDoublyLinked) x->next->previous = NULL;
    head = x->next;
  }
  else{
    // Find element to delete
    while(x != tail){
      if(x->next->name != name)x = x->next;
      else break;
    }
    // If deleting tail:
    if(x->next == tail){
      temp = tail;
      if(isCircularlyLinked){
        x->next = head;
        head->previous = x;
      }
      else x->next = NULL;
      tail = x;
    }
    //Otherwise its in the middle -- Don't need to worry about circular list here
    else{
      temp = x->next;
      x->next = x->next->next;
      if(isDoublyLinked) x->next->previous = x;
    }
  }
  delete temp;
}

void LinkedList::printList(){
    cout << "====== Printing List Elements ======" << endl << endl;
    listElement* x = head;
    if(isDoublyLinked && isCircularlyLinked) cout << "<-->";
    else if(isCircularlyLinked) cout << "<--";
    while(x != NULL){
        if(x->next == NULL){
            cout << x->name << endl;
        }
        else{

            cout << x-> name;
            if(isDoublyLinked) cout << "<-->";
            else cout << "-->";
        }
        if(x != tail)x= x->next;
        else x=NULL;
    }


    cout << endl << "====================================" << endl;
}

void LinkedList::getElementDetails(string name){
  listElement* x = head;
  while(x != NULL) {
    if(x->name == name){
      cout << "Element Name: " << x->name << endl;
      cout <<  "-------------------" << endl;

      if(x == head) cout << "This is the head of the list"<< endl;
      if(x == tail) cout << "This is the tail of the list" << endl;

      cout << "Next Element: ";
      if(x->next == NULL) cout << "N/A" << endl;
      else cout << x-> next->name << endl;

      if(isDoublyLinked){
        cout << "Previous Element: ";
        if(x->previous == NULL) cout << "N/A" << endl;
        else cout << x-> previous->name << endl;
      }
    }

    if(x != tail)x = x->next;
    else x = NULL;
  }
}
