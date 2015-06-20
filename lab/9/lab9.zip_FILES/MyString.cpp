// Course: CS 14 spring 2012
//
// First Name: samuel
// Last Name: villarreal
// UCR Username: svill017
// UCR Email Address: svill017@ucr.edu
//
// Lecture Section: 001
// Lab Section: 021
// TA: Krystof L
//
// Assignment: lab 9
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================================
#include <iomanip>      // provides setw
#include "MyString.h"

const int NOTFOUND = -1;
const int LENGTH = 512;

int MyString::NumAllocations = 0;

MyString::MyString(const char * s)
{
  constructMyString(s);
}

MyString::MyString(const MyString & s)
{
  char * cstring = constructCstring(s.head);
  constructMyString(cstring);
  delete[] cstring;
}

char * MyString::constructCstring(const ListNode * head)
{
  int chars = 0;
  const ListNode * cursor = head;
  while(cursor != NULL) {++chars; cursor = cursor->next;}
  char * cstring = new char[chars + 1];
  for(int i = 0; i < chars; ++i)
  {cstring[i] = head->info; head = head->next;}
  cstring[chars] = NULL;
  return cstring;
}

MyString & MyString::operator =(const MyString & s)
{
  if(this == &s) return *this;
  if(this != NULL) this->~MyString();
  char * cstring = constructCstring(s.head);
  constructMyString(cstring);
  delete[] cstring;
  return *this;
}

char& MyString::operator [](const int index)
{
  int nodes = length();
  if(index >= nodes) error("Index out of range.");
  ListNode * cursor = head;
  for(int i = 0; i < index; ++i) cursor = cursor->next;
  return cursor->info;
}

int MyString::length() const
{
  int count = 0;
  ListNode * cursor = head;
  while(cursor != NULL) {++count; cursor = cursor->next;}
  return count;
}

int MyString::indexOf(char c) const
{
  ListNode * cursor = head;
  int nodes = length();
  for(int i = 0; i < nodes; ++i)
  {
    if(cursor->info == c) return i;
    cursor = cursor->next;
  }
  return NOTFOUND;
}

bool MyString::operator ==(const MyString & s) const
{
  ListNode * thiscursor = head;
  ListNode * scursor = s.head;
  while(thiscursor != NULL)
  {
    if(thiscursor->info != scursor->info) return false;
    thiscursor = thiscursor->next;
    scursor = scursor->next;
  }
  return thiscursor == scursor;
}

const MyString MyString::operator +(const MyString & s) const
{
  int thisChars = length();
  int rhsChars = s.length();
  char * buffer = new char[thisChars + rhsChars + 1];
  ListNode * cursor = head;
  for(int i = 0; i < thisChars; ++i)
  {
    buffer[i] = cursor->info;
    cursor = cursor->next;
  }
  cursor = s.head;
  for(int i = thisChars; i < thisChars + rhsChars; ++i)
  {
    buffer[i] = cursor->info;
    cursor = cursor->next;
  }
  buffer[thisChars + rhsChars] = NULL;
  MyString string(buffer);
  delete[] buffer;
  return string;
}

MyString & MyString::operator +=(const MyString & s)
{
  *this = *this + s;
  return *this;
}

MyString MyString::reverse() const
{
  int nodes = length();
  ListNode * cursor = head;
  char * buffer = new char[nodes + 1];
  for(int j = nodes - 1; j >= 0; --j)
  {
    buffer[j] = cursor->info;
    cursor = cursor->next;
  }
  buffer[nodes] = NULL;
  MyString string(buffer);
  delete[] buffer;
  return string;
}

void MyString::print(std::ostream & out) const
{
  ListNode * cursor = head;
  while(cursor != NULL) {out << cursor->info; cursor = cursor->next;}
  //out << NULL;
}

void MyString::read(std::istream & in)
{
  char * buffer = new char[LENGTH];
  in >> std::setw(LENGTH) >> buffer;
  this->~MyString();
  constructMyString(buffer);
  delete[] buffer;
}

MyString::~MyString()
{
  while(head != NULL)
  {
    ListNode * next = head->next;
    deleteNode(head);
    head = next;
  }
}

void MyString::constructMyString(const char * s)
{
  int chars = numChars(s);
  head = createNode(s[0]);
  ListNode * cursor = head;
  for(int i = 1; i < chars - 1; ++i)
  {
    cursor->next = createNode(s[i]);
    cursor = cursor->next;
  }
}

int MyString::numChars(const char* s) const
{
  int count = 0;
  do {++count;} while(*s++ != NULL);
  for(int i = 0; i < count; ++i) s--;
  return count;
}

ListNode* MyString::createNode(char c, ListNode* next)
{
  
  ListNode* node = new ListNode;
  node->info = c;
  node->next = next;
  this->NumAllocations++;
  return node;
}

void MyString::deleteNode(ListNode* node)
{
  delete[] node;
  this->NumAllocations--;
}


void MyString::giveHalf( MyString * even )
{
  int half = 2;
  if(head->next == NULL) return;
	ListNode * even_t = even->head;
  ListNode * temp = this->head;
  for (int index = 0; temp ; temp = temp->next )
  {
    if(index % half == 0)
    {
      if(even_t == NULL)
      even_t = temp->next;
      else
      {
        even_t->next = temp->next;
        even_t = even_t->next;
      }
      temp->next = even_t->next;
    }
  }
  even_t = NULL;
}
