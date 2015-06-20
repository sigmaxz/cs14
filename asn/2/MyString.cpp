// Course: CS 14 Spring 2012
//
// First Name: Samuel
// Last Name: Villarreal
// UCR Username: svill017
// UCR Email Address: svill017@student.ucr.edu
//
// Lecture Section: 001
// Lab Section: 022
// TA: Krystof Litomisk
//
// Assignment: assignment 2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================================

#include "MyString.h"
#include <iostream>

using namespace std;

int MyString::NumAllocations = 0;

//constructor from array
MyString::MyString(const char * s )
{
  int track = 0;
  for (; s[track] != '\0'; track++);
  if(s[0] == '\0')// if empty
  {
    head = NULL;
  }
  else// if not empty
  {
    ListNode* pre = NULL ;
    for(int i = 0; i < track; i++)
    {
      ListNode* temp = new ListNode;
      temp -> data = s[i];
      if( i == 0)
      {
         head = temp;
         pre = temp;
       }
      else
      {
      pre->next = temp;
      pre = temp;
      }
    }
    pre->next = NULL;
  }
  MyString::NumAllocations += track;
  
}

//copy constructor
MyString::MyString(const MyString & s)
{
  con(s);
}

//destructor
MyString::~MyString()
{
  de();
}

//asighnment opperator
MyString & MyString::operator =(const MyString & s)
{
  de();
  this->con(s);
  return *this;
}

//returns index
char & MyString::operator [](int index)
{
  if(index <= 0 || index > length()) error("out of bounds");
  ListNode* a = head;
  for(int i = 0; i < index ; i++)
  {
    a = a->next;
  }
  return a->data;
  
}

//returns length
int MyString::length() const
{
  int count = 0;
  ListNode* a = head;
  for (;a != NULL;count++)
  {
    a = a->next;
  }
    return count;
  
}

//returns position
int MyString::indexOf(char c) const
{
  ListNode* pos = head;
  if(length()== 0)
  {
    error("empty");
     return false;
   }
  for(int i = 0; i < length();i++)
  {
    if(pos->data == c)
    {
      return i;
    }
    pos = pos->next;
  }
  error("cannot be found");
  return -1;
}

//bollean operator
bool MyString::operator ==(const MyString & s) const
{
  if(length() != s.length())return false;
  if(length() == 0 && s.length() == 0) return true;
  ListNode* a = head;
  ListNode* b = s.head;
  for(int i = 0; i < s.length() ;i++)
  {
    if(a->data != b->data) return false;
    if(s.length() != 0)
    {
      a = a->next;
      b = b->next;
    }
  }
  return true;
}

//addition operator to combine two MyString
const MyString MyString:: operator +(const MyString & s) const
{
  MyString a = MyString(*this);
  if(s.length() == 0) return *this;
  if(length() == 0)
  {
    MyString b = MyString(s);
    return b;
  }
  ListNode* c = a.head;
  MyString::NumAllocations += a.length() +s.length();
  while(c->next)
  {
     c= c->next;
  }
  MyString* q= new MyString(s);

  c->next = q->head;

  return a;
}

//same as addition operator different syntax
MyString & MyString::operator +=(const MyString & s)
{
  *this = *this + s;
  return *this;
}

//makes a reverse of the implicit 
MyString MyString::reverse() const
{
  MyString* a = new MyString();
  if(length() == 0) 
  {
    a->head = NULL;
    return *a;
  }
  if(length() == 1)
  {
    
    MyString b = MyString(*this);
    return b;
  }
  ListNode* pos = head;
  ListNode* pre = NULL;
  for (int i = 0; i < length() ; i++)
  {
    ListNode* temp = new ListNode();
    temp->data = pos->data;
    temp->next = pre;
    pre = temp;
    pos = pos->next;
  }
  a->head = pre;
  return *a;
}

//prints
void MyString::print(std::ostream & out) const
{
  ListNode* a = head;
  for(int i = 0; i < length(); i++)
  {
    out << a->data;
    a = a->next;
  }
}

//reads in to a MyString from the istream
void MyString::read(std::istream & in)
{
  ListNode* p = NULL;
  if(!in.good()) return;
  char a;
  while(in)
  {
    if(head == NULL)
    {
      ListNode* temp2= new ListNode;
      in >> a;
      temp2->data =a ;
      head = temp2;
      temp2->next= NULL;
      p = head;
    }
    else
    {
      ListNode* temp = new ListNode;
      in >> a;
      temp->data = a;
      temp->next = NULL;
      p->next = temp;
      p = temp;
    }
    MyString::NumAllocations++;
  }

}

//constructs
void MyString:: con(const MyString & s)
{
  ListNode* cur = s.head;
  if(cur == NULL){ head = NULL; return;}
  ListNode* temp = NULL;
  ListNode* pre = NULL;
  for(int i = 0; i < s.length() || (s.length() == 0 && i != 1); i++)
  {
    temp = new ListNode();
    if( i == 0)
    {
      head = temp;
     }
     else
     {
      pre->next = temp;
    }
    temp -> data = cur->data;
    pre = temp;
    if(s.length() != 0 && i != s.length() -1)
    {
      cur= cur->next;
    }
    
  }
  pre ->next = NULL;
  MyString::NumAllocations += s.length();
  
}

//destructs
void MyString::de()
{
  MyString::NumAllocations -= length();
  ListNode* temp;
  while(head != NULL)
  {
    temp = head->next;
    delete head;
    head = temp;
  }
}
