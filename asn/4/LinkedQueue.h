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
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Queue.h"

struct Qnode
{
  std::string data;
  Qnode* next;
};

class LinkedQueue : public Queue
{
private:
  int size;
  Qnode* qfront;
  Qnode* back;

public:
  LinkedQueue();
  LinkedQueue(const LinkedQueue &lq);
  LinkedQueue& operator =(const LinkedQueue &lq);
  virtual ~LinkedQueue();
  virtual void enq(const std::string &s) ;
  virtual void deq() ;
  virtual std::string front() const;
  virtual bool isEmpty() const ;
  virtual bool isFull() const;
};

#endif
