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
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>                 // provides: istream, ostream

class MyString
{
public:

  MyString(const char * s = "");
  // Precondition: none
  // Postcondition: buf points to a new null-terminated char array
  // containing the c-string in s
  MyString(const MyString & s);
  // Precondition: none
  // Postcondition: buf points to a new null-terminated char array
  // containing the c-string in s
  MyString & operator =(const MyString & s);
  // Precondition: none
  // Postcondition: Return value is a reference to *this object after
  // copying the c-string in s to *this object
  char & operator [](int index);
  // Precondition: none
  // Postcondition: Return value is the character in position denoted by index
  int length() const;
  // Precondition: none
  // Postcondition: Return value is the number of letters in the c-string
  int indexOf(char c) const;
  // Precondition: none
  // Postcondition: Return value is the index of the first occurrence
  // of c in the array
  bool operator ==(const MyString & s) const;
  // Precondition: none
  // Postcondition: Return value is true if the c-strings are equal
  const MyString operator +(const MyString & s) const;
  // Precondition: none
  // Postcondition: Return value is the contents of a new MyString, which
  // has a c-string that is the catenation of *this with s appended to it
  MyString & operator +=(const MyString & s);
  // Precondition: none
  // Postcondition: Return value is the contents of MyString, which now
  // has the c-string in s appended to its c-string
  MyString reverse() const;
  // Precondition: none
  // Postcondition: Return value is the contents of a new MyString object,
  // which has characters in reverse order
  void print(std::ostream & out) const;
  // Precondition: out is an open ostream
  // Postcondition: c-string pointed to by buf is printed to out
  void read(std::istream & in);
  // Precondition: in is an open istream
  // Postcondition: buf points to a null-terminated char array with chars in
  ~MyString();
  // Precondition: none
  // Postcondition: All dynamically allocated memory has been deallocated

  void error(const char * s) const
  {std::cerr << "Error: " << s << std::endl; throw 0;}
  // Precondition: s is a null-terminated character array
  // Postcondition: c-string s is printed to standard error (cerr)
  static int getMemoryAllocation()
  {return NumAllocations;}
  // Precondition: none
  // Postcondition: Return value is the number of bytes allocated

private:

  char * buf;
  static int NumAllocations;
};

inline std::ostream & operator <<(std::ostream & out, const MyString & str)
// Precondition: out is an open output stream, str has publc member print
// Postcondition: Return value is a reference to out
{str.print(out); return out;}
inline std::istream & operator >>(std::istream & in, MyString & str)
// Precondition: in is an open input stream, str has public member read
// Postcondition: Return value is a reference to in
{str.read(in); return in;}

#endif
