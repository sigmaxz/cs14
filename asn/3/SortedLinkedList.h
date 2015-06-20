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

#ifndef SORTED_LINKED_LIST_H
#define SORTED_LINKED_LIST_H

#include <string>
#include "SortedList.h"

struct ListNode
{
  std::string word;
  ListNode * next;
  ListNode(const std::string word = "", ListNode * const next = NULL)
  : word(word), next(next) {SortedList::NumAllocations++;}
  ~ListNode() {SortedList::NumAllocations--;}
};

class SortedLinkedList : public SortedList
{
public:
  SortedLinkedList();
  // Precondition: none
  // Postcondition: head points to NULL (i.e., empty list)
  SortedLinkedList(const SortedLinkedList & source);
  // Precondition: none
  // Postcondition: head points to a new list that is equal to source's list
  ~SortedLinkedList();
  // Precondition: none
  // Postcondition: All nodes in list pointed to by head have benn delete[]ed
  SortedLinkedList & operator =(const SortedLinkedList & rhs);
  // Precondition: none
  // Postcondition: head points to a new list that is equal to source's list

  void insert(const std::string & word);
  bool find(const std::string & word) const;
  void remove(const std::string & word);

  bool isEmpty() const {return head == NULL;}
  // Precondition: none
  // Postcondition: Return value is true if list has no words
  bool isFull() const {return false;}
  // Precondition: none
  // Postcondition: Return value is true if cannot hold more words

private:
  ListNode * head;    // points to first node in linked-list

  void create_list(const SortedLinkedList & source);
  void destroy_list();
};

#endif
