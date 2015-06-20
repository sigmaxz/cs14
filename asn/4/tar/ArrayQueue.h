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
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "Queue.h"

class ArrayQueue : public Queue
{
  
private:
  std::string* arr;
  int qfront;
  int back;
  int size;
  
public:
  ArrayQueue();
  ArrayQueue(const ArrayQueue &as);
  ArrayQueue& operator =(const ArrayQueue &as);
  virtual ~ArrayQueue();
  virtual void enq(const std::string & s) ;
  virtual void deq();
  virtual std::string front() const;
  virtual bool is_empty() const ;
  virtual bool is_full() const ;
};

#endif
