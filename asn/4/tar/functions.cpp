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

 void Stack::fill_all(Stack & stack , const std::string & filename)
{
  ifstream in(filename.c_str());
  string hold;
  while(in >> hold && !stack.is_full()) 
  {
    stack.push(hold);
  }
}

 void Queue::fill_all(Queue & queue, const std::string & filename)
{
  ifstream in(filename.c_str());
  string hold;
  while(in >> hold && !queue.is_full())
  {
    queue.enq(hold);
  }
}
    

 void Stack::empty_all(Stack & stack, const std::string & filename)
{
  ofstream out(filename.c_str());
  while(!stack.is_empty())
  {
    out << stack.top() << endl;
    stack.pop();
  }
}

 void Queue::empty_all(Queue & queue, const std::string & filename)
{
  ofstream out (filename.c_str());
  while(!queue.is_empty())
  {
    out << queue.front() << endl;
    queue.deq();
  }
}

bool is_balanced(const std::string & brackets)
{
  if(brackets == "") return true;
  LinkedStack ls;
  for (unsigned i = 0; i < brackets.size() ; i++)
  {
    string c = brackets.substr(i,1);
    if(c == "[" || c == "(" || c == "{")
    {
      ls.push(c);
    }
    if(c == "]" )
    {
      if(!ls.is_empty() && ls.top() == "[" )
      {
        ls.pop();
      }
      else return false;
    }
    if(c == "}")
    {
      if(!ls.is_empty() && ls.top() == "{" )
      {
        ls.pop();
      }
    }
    if( c == ")" )
    {
      if(!ls.is_empty() && ls.top() == "(" )
      {
        ls.pop();
      }
      else return false;
    }
  }
  
  if(ls.is_empty()) return true;
  return false;
}
  

