/***************************************************************************
** Program name: Menu.cpp
** Name:         Story Caplain
** Date:         02/18/19
** Description:  This .cpp file is an easily modifiable menu function.
***************************************************************************/
#include "Menu.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int Menu() {

  int choice = 0;

  cout << "\n\n" << "Which option would you like?" << endl;

  cout << "\nOption 1: Add a value to the back of the queue" << endl;

  cout << "Option 2: Display the front value of the queue" << endl;

  cout << "Option 3: Remove the first node of the queue" << endl;

  cout << "Option 4: Display the queue's content" << endl;

  cout << "Option 5: Quit" << endl;
  
  cout << "\nChoice (enter a number): ";
  int val = 1;
  cin  >> choice;
  while(val==1) {
    if(cin.fail() || choice < 1 || choice > 5) {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "\nOops! Invalid input." << endl;
      cout << "Enter a 1, 2, 3, 4 or 5: ";
      cin  >> choice;
    }
    else if(!cin.fail()) {
      val = 0;
    }
  }
  cin.clear();
  cin.ignore(256, '\n');

  return choice;

}
