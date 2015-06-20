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
#include <fstream>
#include "LinkedStack.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

void Stack::fill_all(Stack & stack, const string & filename)
{
  ifstream in(filename.c_str());
  string hold;
  while(!in.eof() && !stack.isFull()) 
  {
    in >> hold;
    stack.push(hold);
  }
}

void Queue::fill_all(Queue & queue, const string & filename)
{
  ifstream in(filename.c_str());
  string hold;
  while(!in.eof() && !queue.isFull())
  {
    in >> hold;
    queue.enq(hold);
  }
}
    

void Stack::remove_all(Stack & stack, const string & filename)
{
  ofstream out(filename.c_str());
  while(!stack.isEmpty())
  {
    out << stack.top() << endl;
    stack.pop();
  }
}

void Queue::remove_all(Queue & queue, const string & filename)
{
  ofstream out (filename.c_str());
  while(!queue.isEmpty())
  {
    out << queue.front() << endl;
    queue.deq();
  }
}

bool is_balanced(string brackets)
{
  if(brackets == "") return true;
  LinkedStack ls;
  for (unsigned i = 0; i < brackets.size() ; i++)
  {
    string c = brackets.substr(i,i+1);
    if(c == "[" || c == "(" || c == "{")
    {
      ls.push(c);
    }
    else if(c == "]" )
    {
      if(ls.top() == "[")
      {
        ls.pop();
      }
      else return false;
    }
    else if(c == "}")
    {
      if(ls.top() == "{")
      {
        ls.pop();
      }
    }
    else if( c == ")" )
    {
      if(ls.top() == "(")
      {
        ls.pop();
      }
      else return false;
    }
    else 
    {
      if(ls.isEmpty()) return true;
    }
  }
  if(ls.isEmpty()) return true;
  return false;
}
  

