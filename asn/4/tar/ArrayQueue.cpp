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
  qfront = 0;
  back = 0;
  size = 0;
}

ArrayQueue::ArrayQueue(const ArrayQueue &as)
{
  arr = new string[45500];
  qfront = 0;
  if(as.size == 0)
  {
    size = 0;
    back = 0;
    return;
  }

  for (signed i = 0; i < 45500 ; i++)
  {
    enq(as.arr[i]);
  }
  qfront = as.qfront;
  back = as.back;
  size = as.size;
}

ArrayQueue& ArrayQueue::operator =(const ArrayQueue &as)
{
  delete[] arr;
  arr = new string[45500];
  qfront = 0;
  if(as.size == 0)
  {
    size = 0;
    back = 0;
    return *this;
  }

  for (signed i = 0; i < 45500 ; i++)
  {
    enq(as.arr[i]);
  }
  qfront = as.qfront;
  back = as.back;
  size = as.size;
  return *this;
}
  

ArrayQueue::~ArrayQueue()
{
  delete[] arr;
}

void ArrayQueue::enq(const std::string & s)
{
 
    if(is_full())
    {
      throw ContainerOverflow("Container Overfow");
    }
    if(is_empty())
    {
      size++;
      arr[qfront] = s;
      back = qfront;
      return;
    }
    else if(back == 45500-1) 
    {
      back = 0;
      arr[back] = s;
      size++;
    }
    else
    {
      size++;
      back++;
      arr[back] = s;
    }
}

  
void ArrayQueue::deq()
{
 
    if(is_empty())
    {
      throw ContainerUnderflow("Container Underflow");
    }
    size--;
    if(qfront == 45500-1) qfront = 0;
    else
    qfront++;
  
}

string ArrayQueue::front() const
{
  if(is_empty())
  {
    cerr << "empty" << endl;
    return "err::empty";
  }
  return arr[qfront];
}
  
bool ArrayQueue::is_empty() const
{
  if( size == 0) return true;
  return false;
}

bool ArrayQueue::is_full() const
{
  if( size == 45500) return true;
  return false;
}
