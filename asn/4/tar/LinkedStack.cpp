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
#include "LinkedStack.h"
#include "ContainerUnderflow.h"
#include "ContainerOverflow.h"

using namespace std;

LinkedStack::LinkedStack()
{
  size = 0;
  ltop = NULL;
}
      
LinkedStack::LinkedStack(const LinkedStack &as)
{
  size = 0;
  ltop = NULL;
  if(!as.is_empty()) 
  {
    Snode* temp = as.ltop;
    while(temp)
    {
      push(temp->data);
      temp = temp+1;
    }
  }
}

LinkedStack& LinkedStack::operator =(const LinkedStack &as)
{
  Snode* temp = ltop;
  while(size != 0)
  {
    Snode* temp2 = temp;
    if(size != 1) temp = temp->next;
    delete temp2;
    size--;
  } 
  size = 0;
  ltop = NULL;
  if(!as.is_empty()) 
  {
    Snode* temp = as.ltop;
    while(temp)
    {
      push(temp->data);
      temp = temp+1;
    }
  }
  return *this;
}

LinkedStack::~LinkedStack() 
{
  Snode* temp = ltop;
  while(size != 0)
  {
    Snode* temp2 = temp;
    if(size != 1) temp = temp->next;
    delete temp2;
    size--;
  } 
}

void LinkedStack::push(const std::string & s) 
{
    if( is_full() )
    {
     throw ContainerOverflow("Container Overflow");
    }
 
    size++;
    Snode* temp = new Snode;
    temp->data = s;
    temp->next = ltop;
    ltop = temp;
  
}

void LinkedStack::pop()
{

    if(is_empty())
    {
      throw ContainerUnderflow("Container Underflow");
    }
    Snode* temp = ltop;
    if(ltop->next) ltop = ltop->next;
    delete temp;
    size--;

}  
    
string LinkedStack::top() const
{
  return ltop->data;
} 

bool LinkedStack::is_empty() const
{
  if(size == 0) return true;
  return false;
}

bool LinkedStack::is_full() const
{
  if(size == 45500) return true;
  return false;
}
