/**************************************************************************
** Program Name: Main.cpp
** Name:         Story Caplain
** Date:         02/19/19
** Description:  This program lets users interact in various ways with a 
**               circularly linked list.
***************************************************************************/
#include <iostream>
#include "Menu.hpp"
#include "Queue.hpp"

int main() {

  std::cout << "\n\nWelcome to Queue. A program that lets you perform\n";
  std::cout << "various functions with a circular linked list.\n";

  int val = 0;
  bool playing = true;
  Queue q;
 
  while(playing==true) {
  
    int choice = Menu();
  
    //user wants to add to back of queue
    if(choice==1) {
  
      std::cout << "\nEnter the number you want to add to the queue: ";
      std::cin  >> val;

      //validate input
      int validate = 1;
      while(validate==1) {
        if(std::cin.fail()) {
          std::cin.clear();
          std::cin.ignore(256, '\n');
          std::cout << "Oops! Invalid input." << std::endl;
          std::cout << "Enter an integer: ";
          std::cin  >> val;
        }
        else if(!std::cin.fail()) {
          validate = 0;
        }
      }
      std::cin.clear();
      std::cin.ignore(256, '\n');
  
      //call add back function
      q.addBack(val);
    }

    //user wants to add to front of queue
    else if(choice==2) {

      bool check = q.isEmpty();

      if(check==false) {
        
        int front = q.getFront();
        
        std::cout << "\nThe head of the list is: "<< front << std::endl;
      }

      else {
         std::cout << "\n\nEmpty list!\n"; 
      }
    }

    //user wants to remove the first node of the queue
    else if(choice==3) {
      q.removeFront();
    }

    //user wants to print queue
    else if(choice==4) {
      q.printQueue();
    }
    
    //user quits
    else {
      std::cout << "\n\nThanks for using Queue! Goodbye...\n\n";
      playing = false;
    }
  }
  return 0;
}
