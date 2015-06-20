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

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "Stack.h"

class ArrayStack : public Stack
{
private:
  std::string* arr;
  int size;
  std::string* atop;
  
public:
  ArrayStack();
  ArrayStack(const ArrayStack &as);
  ArrayStack& operator =(const ArrayStack &as);
  virtual ~ArrayStack();
  virtual void push(const std::string & s);
  virtual void pop() ;
  virtual std::string top() const ;
  virtual bool isEmpty() const ;
  virtual bool isFull() const ;
};

#endif



