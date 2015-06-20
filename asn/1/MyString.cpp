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
// Assignment: assignment 1
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================================

#include "MyString.h"

using namespace std;

//static NumAllocations set
int MyString::NumAllocations = 0;

//two for one constructor
MyString:: MyString(const char * s )
{
  size_t i;
  for(i = 0; s[i]!= '\0'; i++);
  MyString::NumAllocations += i +1;
  buf = new char[i+1];
  buf[i] = '\0';
  for (size_t b = 0; b < i; b++) 
  {
    buf[b]= s[b];
  }
  
}

//copy constructor
MyString:: MyString(const MyString & s)
{
  buf = new char[s.length()+1];
  buf[s.length() +1] = '\n';
  for (int i = 0; i < s.length()+1; i++)
  {
    buf[i] = s.buf[i];
  }
  MyString::NumAllocations +=  s.length()+1;
  
}

//overloaded = cheacking if its the same then remaking into copy if false
MyString & MyString:: operator =(const MyString & s)
{
  if(*this == s) return *this;
  MyString::NumAllocations -= length() +1;
  MyString::NumAllocations += s.length()+1;
  delete[] buf;
  buf = new char[s.length()+1];
  buf[s.length()+1] = '\0';
  for (int i = 0; i <= s.length() ; i++)
  {
    buf[i] = s.buf[i];
  }
  return *this;
  
}

// index operator giving error if necessary
char &  MyString::operator [](int index)
{
  if(index > length()) 
  {
    error(buf); 
    return buf[0];// satisfy return
  }
  else return buf[index];
}

//return length no counting the NULL
int MyString:: length() const
{
  size_t i;
  for ( i = 0; buf[i]!= '\0' ; i++); // possible off by one
  return i;
}

//looks for index 
int MyString:: indexOf(char c) const
{
  for (int i = 0; i< length(); i++)
  {
    if(buf[i] == c) return i;
  }
  error(buf);
  return 0;
}

//boolean operator uses for loop to check
bool MyString::operator ==(const MyString & s) const
{
  if( length() != s.length()) return false;
  for(int i = 0; i < length() ; i++)
  {
    if(buf[i] != s.buf[i])
    {
      cout << i;
       return false;
    }
  }
  return true;
}

//copy into a temp then return a MyString using the temp;
const MyString MyString:: operator +(const MyString & s) const
{
  char* temp = new char[ length() + s.length() +1];
  MyString::NumAllocations += s.length();
  int i,j;
  for (i = 0;this->buf[i] != '\0'  ; i++)
  {
    temp[i] = buf[i];
  }
  for (j= 0; s.buf[j] != '\0' ; i++,j++)
  {
    temp[i] = s.buf[j];
  }
  return MyString(temp);
}

// reuse of + operator
MyString & MyString::operator +=(const MyString & s)
{
  *this = *this+ s;
  return *this;
}


MyString MyString:: reverse() const
{
  MyString* m = new MyString;
  int q = 0;
  for (int i = length()-1; i >= 0 ; i--,q++)
  {
    m->buf[q] = buf[i];
  }
  return *m;
}

//helper for <<
void MyString::print(std::ostream & out) const
{
  for (size_t i = 0; buf[i] != '\0' ; i++)
  {
    out << buf[i];
  }
}

//helper for >>
void MyString::read(std::istream & in)
{
  int size;
  char a;
  MyString::NumAllocations -= length()+1;

  for(int i = 0; in; i++)
  {
    in >> this->buf[i];
    size = i;
  } 
  MyString::NumAllocations += length()+1;
}

//deallocates memory at end
MyString::~MyString()
{
  if(this->buf == NULL) return ;
  MyString::NumAllocations -= length() -1;
  delete[] buf;
  
}
