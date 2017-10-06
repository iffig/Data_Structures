#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void menuOptions();
void dispMode(bool _circular, bool _doublyLinked);

int main() {

    bool typeChosen = false;
    bool doublyLinked = false;
    bool circular = false;

    string selection;
    string typeSelection;

    //Establish Linked List Type
    while(typeChosen == false){

        cout << "Linked List Options: " << endl;
        cout << "1. Singly Linked" << endl;
        cout << "2. Doubly Linked" << endl;
        cout << "3. Circularly Singly Linked" << endl;
        cout << "4. Circularly Doubly Linked" << endl;

        getline(cin, typeSelection);

        if(typeSelection > "0" &&  typeSelection < "5" ){
          if(typeSelection == "2" || typeSelection == "4"){ doublyLinked = true;}
          if(typeSelection == "3" || typeSelection == "4"){ circular = true;}
          dispMode(circular, doublyLinked);
          typeChosen = true;
        }
        else{
            cout << "Invalid Input" << endl;
        }

    }

    cout << endl << endl;

    LinkedList* list = new LinkedList(circular, doublyLinked);

    while(selection != "q"){

        menuOptions();

        getline(cin, selection);
        cout << endl;

        // Insert Elements
        if(selection == "1"){
          string name;
          string previous;

          cout << "Enter Element Name: ";
          getline(cin, name);
          cout << "Enter Element to Insert After: ";
          getline(cin, previous);

          list -> addElement(previous, name);

        }
        // Remove Elements
        else if(selection == "2"){
          string name;

          cout << "Enter Element Name: ";
          getline(cin, name);

          list -> removeElement(name);
        }
        // Print List
        else if(selection == "3"){
          list-> printList();
        }
        // Display element properties
        else if(selection =="4"){
          string name;

          cout << "Enter Element Name: ";
          getline(cin, name);

          list->getElementDetails(name);
        }
        else if (selection != "q"){
          cout << "Invalid input" << endl;
        }
        cout << endl;
    }
}

void menuOptions(){
    cout << "=== Linked List Operations ===" << endl;
    cout << "1. Insert Element" << endl;
    cout << "2. Remove Element" << endl;
    cout << "3. Print List" << endl;
    cout << "4. View Element Details" << endl;

    cout << "Press 'q' to quit" << endl;
}

void dispMode(bool _circular, bool _doublyLinked){
  cout << endl << "You have chosen a ";
  if(_circular) cout << "circularly, ";
  if (_doublyLinked) cout << "doubly ";
  if (!_doublyLinked) cout << "singly ";
  cout << "linked list." << endl ;
}
