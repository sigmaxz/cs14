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
#include "ArrayQueue.h"
#include "ContainerUnderflow.h"
#include "ContainerOverflow.h"

using namespace std;

ArrayQueue::ArrayQueue()
{
  arr = new string[45500];
  qfront = &arr[0];
  back = &arr[0];
  size = 0;
}

ArrayQueue::ArrayQueue(const ArrayQueue &as)
{
  arr = new string[45500];
  qfront = &arr[0];
  if(as.size == 0)
  {
    size = 0;
    back = &arr[0];
    return;
  }

  for (signed i = 0; i < as.size ; i++)
  {
    enq(as.qfront[i]);
  }
  size = as.size;
}

ArrayQueue& ArrayQueue::operator =(const ArrayQueue &as)
{
  delete[] arr;
  arr = new string[45500];
  qfront = &arr[0];
  if(as.size == 0)
  {
    size = 0;
    back = &arr[0];
    return *this;
  }

  for (signed i = 0; i < as.size ; i++)
  {
    enq(as.qfront[i]);
  }
  size = as.size;
  return *this;
}
  

ArrayQueue::~ArrayQueue()
{
  delete[] arr;
}

void ArrayQueue::enq(const std::string & s)
{
  try
  {
    if(isFull())
    {
      throw ContainerOverflow("Container Overfow");
    }
    if(isEmpty())
    {
      size++;
      *qfront =s;
      back = qfront;
      return;
    }
    if(*back == arr[45500-1]) 
    {
      back = &arr[0];
      *back = s;
      size++;
    }
    else
    {
      size++;
      back++;
      *back = s;
    }
  }
  catch(ContainerOverflow e)
  {
    cerr << e.err << endl;
  }
}
  
void ArrayQueue::deq()
{
  try
  {
    if(isEmpty())
    {
      throw ContainerUnderflow("Container Underflow");
    }
    size--;
    qfront++;
  }
  catch(ContainerUnderflow e)
  {
    cerr << e.err << endl;
  }
}

string ArrayQueue::front() const
{
  if(isEmpty())
  {
    cerr << "empty" << endl;
    return "err::empty";
  }
  return *qfront;
}
  
bool ArrayQueue::isEmpty() const
{
  if( size == 0) return true;
  return false;
}

bool ArrayQueue::isFull() const
{
  if( size == 45500) return true;
  return false;
}
