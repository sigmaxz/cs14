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
// Assignment: assignment 4
// 
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
// 
// ===========================================================================

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "Stack.h"
using namespace std;

struct Snode
{
  std::string data;
  Snode* next;
};
  
class LinkedStack: public Stack
{
private:
  int size;
  Snode* ltop;
  
public:
  LinkedStack();
  LinkedStack(const LinkedStack &as);
  LinkedStack& operator =(const LinkedStack &as);
  virtual ~LinkedStack() ;
  virtual void push(const std::string & s) ;
  virtual void pop();
  virtual string top() const ;
  virtual bool isEmpty() const;
  virtual bool isFull() const;
};

#endif

