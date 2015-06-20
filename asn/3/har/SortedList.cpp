// Course: CS 14 Spring 2012
// 
// First Name: Samuel
// Last Name: Villarreal
// UCR Username: svill017
// UCR Email Address: svill017@ucr.edu
// 
// Lecture Section: 001
// Lab Section: 021
// TA: Krystof Litomisky
// 
// Assignment: assignment 3
// 
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
// 
// ===========================================================================

#include "Timer.h"
#include "SortedList.h"

size_t SortedList::NumAllocations = 0;

using namespace std;

void SortedList::batch
(void (SortedList::*op)(const string &), const string & filename)
{
  ifstream a(filename.c_str());
  std::string hold;
  while(!a.eof())
  {
    a >> hold;
    (this->*op)(hold);
  }
  // *** REPLACE WITH YOUR IMPLEMENTATION ***
  // a call to the function pointer "op" passed in as an argument to this function
  // is made by: "(this->*op)(word);" where "word" is a string
}
