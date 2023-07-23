#ifndef sorted_ll
#define sorted_ll

#include <string>
#include "node.h"

class LL {
  NodePtr hol; // head of linked list
  int size;

public:
  LL();
  int isEmpty();
  void insert(int value, string name);
  void printList();
 
  ~LL();
//With doubly linked list

 void printListR();
};

LL::LL() {
  this->hol = NULL;
  size = 0;
}

LL::~LL() {
  cout << "deleting all nodes" << endl;
  NodePtr t;
  t = hol;
  int i;
  while(hol!=NULL) {
    hol = hol->get_next();
    delete t;
    t = hol;
  }
}

void LL::insert(int value, string name) {
  NodePtr newPtr;      // pointer to new node
  NodePtr previousPtr; // pointer to previous node in list
  NodePtr currentPtr;  // pointer to current node in list

  newPtr = new Node(value, name); // create node & put value in

  if (newPtr != NULL) { // is space available

    previousPtr = NULL;
    currentPtr = hol;
    // loop to find the correct location in the list
    while (currentPtr != NULL && value > currentPtr->get_data()) {
      previousPtr = currentPtr;            // walk to ...
      currentPtr = currentPtr->get_next(); // ... next node
                                          
    } // end while

    // insert new node at beginning of list
    if (previousPtr == NULL) {
        newPtr->set_next(hol);
      
      if(hol)
        hol->set_prev(newPtr);
        hol = newPtr;
       
      }  // end if
    else { 
      // insert new node between previousPtr and currentPtr
      previousPtr->set_next(newPtr);
      newPtr->set_prev(previousPtr);
      
      newPtr->set_next(currentPtr);
      
      if(currentPtr!=NULL)
      currentPtr->set_prev(newPtr);
      
    } // end else
    ++size;
  } // end if
  else {
    cout << value << " not inserted. No memory available." << endl;
  } // end else
} // end function insert

void LL::printList() {
  NodePtr currentPtr = hol;
  // if list is empty
  if (size == 0) {
    cout << "List is empty." << endl;
  } // end if
  else {

    // while not the end of the list
    // while ( currentPtr != NULL ) {
    int i;
    for (i = 0; i < size; i++) {
      currentPtr->print();
      //cout << "  ->";
      currentPtr = currentPtr->get_next();
    } // end while

    //puts("NULL\n");
  } // end else
} // end function printList

// return 1 if the list is empty, 0 otherwise
int LL::isEmpty() { return hol == NULL; } // end function isEmpty

#endif