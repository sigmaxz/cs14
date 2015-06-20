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
{
  arr = new string[45500];
  size = 0;
  atop = 0;
}

ArrayStack::ArrayStack(const ArrayStack &as)
{
  arr = new string[45500];
  if(as.size == 0)
  {
    size = 0;
    atop = 0;
    return;
  }

  for (int i = 0; i < as.size ; i++)
  {
    arr[i] = as.arr[i];
    atop = i;
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
    atop = 0;
    return *this;
  }

  for (int i = 0; i < as.size ; i++)
  {
    arr[i] = as.arr[i];
    atop = i;
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
    if( is_full() )
    {
      throw ContainerOverflow("Container Overfow");
    }
    size++;
    arr[size] = s;
    atop++;
    return;
  

}

void ArrayStack::pop()
{
 
    if(is_empty() )
    {
      throw ContainerUnderflow("Container Underflow");
    }
    size--;
    atop--;
  

}

string ArrayStack::top() const
{
  return arr[atop];
}

bool ArrayStack::is_empty() const
{
  if(size == 0) return true;
  return false;
}

bool ArrayStack::is_full() const
{
  if(size == 45500) return true;
  return false;
}
  
