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
  friend struct test_23;
  friend struct test_24_25;
  friend struct test_26_27;
  friend struct test_28_30;
  friend struct test_31_33;
  friend struct test_34_35;
  friend struct test_36_37;
  friend struct test_38_39;
  friend struct test_40_42;

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
  std::string operator [](const size_t & index) const
  // Precondition: none
  // Postcondition: Return rvalue is object of type string at location index
  {
    size_t count = 0;
    ListNode * node = head;
    while(node && count != index) {node = node->next; ++count;}
    if(!node) exit(1);
    return node->word;
  }
  size_t size_cassej() const
  {
    size_t count = 0;
    ListNode * node = head;
    while(node) ++count;
    return count;
  }

private:
  ListNode * head;    // points to first node in linked-list

  void create_list(const SortedLinkedList & source);
  void destroy_list();
};

#endif
