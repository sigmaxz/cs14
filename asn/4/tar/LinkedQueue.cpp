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
#include <iostream>
#include "LinkedQueue.h"
#include "ContainerUnderflow.h"
#include "ContainerOverflow.h"

using namespace std;

  LinkedQueue::LinkedQueue()
  :size(0), qfront(NULL), back(NULL)
  {}
  
  LinkedQueue::LinkedQueue(const LinkedQueue &lq)
  {
    size = 0;
    qfront = NULL;
    back = NULL;
    if(!lq.is_empty()) 
    {
      Qnode* temp = lq.qfront;
      for (int i = 0; i < lq.size; i++)
      {
        enq(temp->data);
        temp = temp->next;
      }
    }
  }
  
  LinkedQueue& LinkedQueue::operator =(const LinkedQueue &lq)
  {
    Qnode* temp = qfront;
    while(size != 0)
    {
      Qnode* temp2 = temp;
      if(size != 1) temp = temp ->next;
      delete temp2;
      size--;
    }
    size = 0;
    qfront = NULL;
    back = NULL;
    if(!lq.is_empty()) 
    {
      Qnode* temp = lq.qfront;
      for (int i = 0; i < lq.size; i++)
      {
        enq(temp->data);
        temp = temp->next;
      }
    }
    return *this;
  }
  
  LinkedQueue::~LinkedQueue()
  {
    Qnode* temp = qfront;
    while(size != 0)
    {
      Qnode* temp2 = temp;
      if(size != 1) temp = temp->next;
      delete temp2;
      size--;
    }
  } 
  
  void LinkedQueue::enq(const std::string & s) 
  {
   
      if(is_full())
      {
        throw ContainerOverflow("Container Overflow");
      }
      Qnode* temp = new Qnode;
      temp->data = s;
      if(is_empty())
      {
        qfront = temp;
        back = temp;
        size++;
      }
      else
      {
        back->next = temp;
        back = temp;
        size++;
      }
    

}
  
  void LinkedQueue::deq()
  {
   
      if(is_empty())
      {
        throw ContainerUnderflow("Container Underflow");
      }
      Qnode* temp = qfront;
      if(qfront->next) qfront = qfront->next;
      delete temp;
      size--;
    
  
}
  
string LinkedQueue::front() const
  {
    if(is_empty())
    {
      cerr << "empty" << endl;
      return "empty";
    }
    return qfront->data;
  }
  
  bool LinkedQueue::is_empty() const 
  {
    if(size == 0) return true;
    return false;
  }
  
  bool LinkedQueue::is_full() const
  {
    if(size== 45500) return true;
    return false;
  }
