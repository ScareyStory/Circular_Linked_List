/**************************************************************************
** Program Name: Queue.hpp
** Name:         Story Caplain
** Date:         02/18/19
** Description:  This is the header file for the Queue class
***************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>

//Struct holds ptrs to QueueNode objects, and an int for the node's value
struct QueueNode {

  //Number held by node in list
  int val;

  //Pointer to next Node object
  QueueNode *next;

  //Pointer to previous Node object
  QueueNode *prev;

};

class Queue {
 
  private:

  QueueNode *head;

  public:

  //Constructor 
  Queue();

  //Checks if the queue is empty, returns true if empty
  bool isEmpty();

  //Takes a user-inputted integer 
  //Creates a QueueNode with user-inputted integer
  //Then appends it to the back of the list.
  void addBack(int);

  //Returns the value of the node at the front of the queue.
  int getFront();

  //Removes the front QueueNode of the queue and frees the memory.
  void removeFront();

  //Traverses through the queue from head using next pointers 
  //Then prints the values of each QueueNode in the queue.
  void printQueue();

  //Deconstructor
  ~Queue();

};
#endif
