/**************************************************************************
** Program Name: Queue.cpp
** Name:         Story Caplain
** Date:         02/18/19
** Description:  This is the cpp file for the Queue class
***************************************************************************/
#include <iostream>
#include "Queue.hpp"

//Constructor 
Queue::Queue() {

  //Initialize head ptr to null
  head = NULL;

}

//Checks if the queue is empty, returns true if empty
bool Queue::isEmpty() {

  //if head points to null, list is empty, return true
  
  if(head==NULL) {return true;}

  else {return false;}
}

//Takes a user-inputted integer 
//Creates a QueueNode with user-inputted integer
//Then appends it to the back of the list.
void Queue::addBack(int val) {

  //store result of isEmpty in check
  bool check = isEmpty();
  
  //if check is true, list is empty
  if(check==true) {
   
    //head points to a new QueueNode 
    head = new QueueNode;
    
    //Store user's value into the new QueueNode
    head->val = val;
    
    //Set new head's next pointer to point to old head of list
    head->next = head;

    //set old head pointer's previous pointer to new head
    head->prev = head;
  }

  //if not empty
  else if(check==false) {
    //New pointer to QueueNode is equal to head's previous pointer
    //In a circular list head's previous pointer is the tail
    QueueNode *tail = head->prev;

    //Create new QueueNode object
    QueueNode *n = new QueueNode;

    //Store user input into new QueueNode's val member
    n->val = val;

    //Since n is the new head, put it in between tail and head
    
    //First set n's next pointer to the head
    n->next = head;

    //Then set n's prev pointer to the tail
    n->prev = tail;

    //Now link back the old head and tail to the new head

    //Doubly link old head to new head
    head->prev = n;

    //Doubly link old tail to new head
    tail->next = n;
  }
}

//Returns the value of the node at the front of the queue.
int Queue::getFront() {

  bool check = isEmpty();

  if(check==false) {

    //return the value stored in the object pointed to by head
    int front = head->val;

    return front;
  }
  else {
    std::cout << "\n\nEmpty List!\n";
  }
}

//Removes the front QueueNode of the queue and frees the memory.
void Queue::removeFront() {

  //store result of isEmpty in check
  bool check = isEmpty();

  //if nothing to remove
  if(check==true) {
    std::cout << "\n\nList is already empty!\n";
  }

  //else if one or more elements in the list
  //we check this by seeing if head prev and next pointer point to itself
  else {

    //if one element
    if(head==(head->prev) && head==(head->next)) {
      head = NULL;
      delete head;
    }
    
    //else at least two elements
    else {
      //New pointer to Queuenode temp points to head
      QueueNode *temp = head;

      //Set head to point to point to next node
      head = head->next;

      //Set old head's prev pointer to temp's prev pointer
      head->prev = temp->prev;

      //Temp's prev's next points to the old head
      //Make it point to the new head
      temp->prev->next = temp->next;

      //Deallocate the memory used by temp
      delete temp;
    }
  }
}

//Traverses through the queue from head using next pointers 
//Then prints the values of each QueueNode in the queue.
void Queue::printQueue() {

  //check if list is empty
  bool check = isEmpty();

  //if not empty
  if(check==false) {

    //create temporary node
    QueueNode* temp = head->next;

    std::cout << "\nYour queue: ";

    //While the temp node's next pointer is not pointing to the head of the
    //list (aka while the list has not reached the beginning again)
    std::cout << head->val << "  ";

    while(temp != head) {

      //output that node's val
      std::cout << temp->val << "  ";

      //set temp to point to the next node
      temp = temp->next;
    }
    std::cout << std::endl;
  }
  //Else if list is empty, tell user
  else {
    std::cout << "\n\nNothing to print, empty queue\n";
  }
}

//Deconstructor
Queue::~Queue() {
  
  bool check = isEmpty();

  while(check==false) {
  
    //if one element in the list
    //we check this by seeing if head prev and next pointer point to itself
    if(head==head->prev && head==head->next) {
      delete head;
      head = NULL;
    }
    
    //else if at least two elements
    else {
      //New pointer to Queuenode temp points to head
      QueueNode *temp = head;
  
      //Set old head's next pointer to point to itself
      head = head->next;
  
      //Set old head's prev pointer to temp's prev pointer
      head->prev = temp->prev;
  
      //Temp's prev's next points to the old head
      //Make it point to the new head
      temp->prev->next = temp->next;
  
      //Deallocate the memory used by temp
      delete temp;
    }
    //check again if list is empty
    //if it isn't check stays false and loop goes again
    //if list is empty than deconstructor ends
    check = isEmpty();  
  }
}
