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
#include "ArrayStack.h"
#include "ContainerUnderflow.h"
#include "ContainerOverflow.h"

using namespace std;

ArrayStack::ArrayStack()
:arr(NULL),size(0), atop(NULL)
{
}

ArrayStack::ArrayStack(const ArrayStack &as)
{
  arr = new string[45500];
  if(as.size == 0)
  {
    size = 0;
    atop = NULL;
    return;
  }

  for (unsigned i = 0; i < as.size ; i++)
  {
    arr[i] = as.arr[i];
    atop = &arr[i];
  }
  size = as.size;
}

 ArrayStack& ArrayStack::operator =(const ArrayStack &as)
 {
   delete[] arr;
   arr = new string[45500];
  if(as.size == 0)
  {
    size = 0;
    atop = NULL;
    return *this;
  }

  for (unsigned i = 0; i < as.size ; i++)
  {
    arr[i] = as.arr[i];
    atop = &arr[i];
  }
  size = as.size;
  return *this;
}
   
ArrayStack::~ArrayStack() 
{
  delete[] arr;
}
  
void ArrayStack::push(const string & s)
{
  try
  {
    if( isFull() )
    {
      throw ContainerOverflow("Container Overfow");
    }
    size++;
    arr[size-1] = s;
    atop = &arr[size-1];
    return;
  }
  catch (ContainerOverflow e)
  {
    cerr << e.err << endl;
  }
}

void ArrayStack::pop()
{
  try
  {
    if(isEmpty() )
    {
      throw ContainerUnderflow("Container Underflow");
    }
    atop--;
  }
  catch(ContainerUnderflow e)
  {
    cerr << e.err << endl;
  }
  
}

string ArrayStack::top() const
{
  return *atop;
}

bool ArrayStack::isEmpty() const
{
  if(size == 0) return true;
  return false;
}

bool ArrayStack::isFull() const
{
  if(size == 45500) return true;
  return false;
}
  
