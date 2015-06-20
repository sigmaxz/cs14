// Course: CS 14 Spring 2012
// 
// First Name: samuel
// Last Name: villarreal
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

#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <fstream>
#include <string>
class SortedList
{
  friend struct ListNode;

public:
  virtual void insert(const std::string &) {exit(1);}
  // Precondition: array is not full
  // Postcondition: word is in proper location in array
  virtual bool find(const std::string &) const {exit(1);}
  // Precondition: none
  // Postcondition: Return value is true if word is in array, false otherwise
  virtual void remove(const std::string &) {exit(1);}
  // Precondition: none
  // Postcondition: word is no longer in array, and there are no gaps between
  // words in the array
  void batch
  (void (SortedList::*op)(const std::string &), const std::string & filename);
  // Precondition: filename refers to plain-text file of words
  // Postcondition: op is called on all the words in the file
  virtual ~SortedList() {}

  virtual bool isEmpty() const {exit(1);}
  // Precondition: none
  // Postcondition: Return value is true if list has no words
  virtual bool isFull() const {exit(1);}
  // Precondition: none
  // Postcondition: Return value is true if cannot hold more words

  static size_t getNumAllocation() {return NumAllocations;}
  // Precondition: none
  // Postcondition: Return value is current number of strings or ListNodes

protected:
  static size_t NumAllocations;   // number of words currently allocated
};

inline bool lessThan(std::string lhs, std::string rhs)
// Precondition: none
// Postcondition: Return true if rhs follows lhs lexicographycally,
// case insensitive
{
  if( lhs == rhs) return false;
  int w = lhs[0];
  int w2 = rhs[0];
  if( w <= 90) w = w+32;
  if( w2 <= 90) w2 = w2 +32;
  if( w < w2) return false;
  std::string a = lhs.substr(1);
  std::string b = rhs.substr(1);
  if(a == b) return false;
  unsigned i = 1;
  while( lhs[i] == rhs[i])
  {
    i++;
    if(i == lhs.size()) return true;
    if(i == rhs.size()) return false;
  }
  char z = lhs[i];
  char x = rhs[i];
  if( z < x) return true;
    
  return false;
  
}

#endif
