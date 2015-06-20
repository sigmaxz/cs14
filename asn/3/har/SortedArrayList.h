// Course: CS 14 Spring 2012
// 
// First Name: John
// Last Name: Smith
// UCR Username: jsmit003
// UCR Email Address: jsmit003@student.ucr.edu
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

#ifndef SORTED_ARRAY_LIST_H
#define SORTED_ARRAY_LIST_H

#include "SortedList.h"

#define CAPACITY 45500

class SortedArrayList : public SortedList
{
  friend struct test_1;
  friend struct test_2_3;
  friend struct test_4_5;
  friend struct test_6_7;
  friend struct test_8_10;
  friend struct test_11_13;
  friend struct test_14_15;
  friend struct test_16_17;
  friend struct test_18_19;
  friend struct test_20_22;
  friend struct sort_t;

public:

  SortedArrayList(size_t capacity = CAPACITY);
  // Precondition: none
  // Postcondition: buf points to a new string array with capacity for
  // capacity words, capacity is initialized to capacity, and size to zero
  SortedArrayList(const SortedArrayList & source);
  // Precondition: none
  // Postcondition: buf points to a new string array that is a copy of
  // source's, capacity equals source.capacity, and size source.size
  ~SortedArrayList();
  // Precondition: none
  // Postcondition: Array of strings is deallocated
  SortedArrayList & operator =(const SortedArrayList & rhs);
  // Precondition: none
  // Postcondition: buf points to a new string array that is a copy of
  // rhs's array, capacity equals rhs.capacity, size equals rhs.size

  void insert(const std::string & word);
  bool find(const std::string & word) const;
  void remove(const std::string & word);

  bool isEmpty() const {return size == 0 && capacity > 0;}
  // Precondition: none
  // Postcondition: Return value is true if list has no words
  bool isFull() const {return size == capacity;}
  // Precondition: none
  // Postcondition: Return value is true if cannot hold more words
  std::string operator [](const size_t & index) const
  // Precondition: none
  // Postcondition: Return rvalue is object of type string at location index
  {
    if(index >= size) exit(1);
    return buf[index];
  }
  size_t size_cassej() const {return size;}

private:

  std::string * buf;     // array of string objects
  size_t capacity;       // size of array
  size_t size;           // list size (number of words in array)

  void create_array(size_t capacity);
  void destroy_array();
  int indexOf(const std::string & word) const;
};

#endif
