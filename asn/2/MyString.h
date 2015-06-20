#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class ListNode
{
public:
  char data;
  ListNode * next;
};

class MyString
{
  friend struct test_1;
  friend struct test_2;
  friend struct test_3_4;
  friend struct test_5;
  friend struct test_6_7;
  friend struct test_8_10;
  friend struct test_11_12;
  friend struct test_13_15;
  friend struct test_16_20;
  friend struct test_21_24;
  friend struct test_25_28;
  friend struct test_29_32;
  friend struct test_33;
  friend struct test_34;

public:

  MyString(const char * s = "");
  // Precondition: none
  // Postcondition: head points to a new linked-list
  // containing the c-string in s; if s is the empty string, then
  // head = NULL
  MyString(const MyString & s);
  // Precondition: none
  // Postcondition: head points to a new linked-list
  // containing the c-string in s
  ~MyString();
  // Precondition: none
  // Postcondition: All nodes in the linked-list have been deallocated
  MyString & operator =(const MyString & s);
  // Precondition: none
  // Postcondition: Return value is a reference to *this object after
  // copying the c-string in s to a new linked-list pointed to by head
  char & operator [](int index);
  // Precondition: none
  // Postcondition: Return value is the character in position denoted by index
  int length() const;
  // Precondition: none
  // Postcondition: Return value is the number of letters in the c-string
  int indexOf(char c) const;
  // Precondition: none
  // Postcondition: Return value is the index of the first occurrence
  // of c in the linked-list
  bool operator ==(const MyString & s) const;
  // Precondition: none
  // Postcondition: Return value is true if the content of the two
  // linked-lists are equal
  const MyString operator +(const MyString & s) const;
  // Precondition: none
  // Postcondition: Return value is the contents of a new MyString, which
  // has a linked-list that is the catenation of *this with s appended to it
  MyString & operator +=(const MyString & s);
  // Precondition: none
  // Postcondition: Return value is the contents of MyString, which now
  // has a linked-list that is the catenation of *this with s appended to it
  MyString reverse() const;
  // Precondition: none
  // Postcondition: Return value is the contents of a new MyString object,
  // which has the nodes in the liinked-list in reverse order
  void print(std::ostream & out) const;
  // Precondition: out is an open ostream
  // Postcondition: The characters in the linked-list are printed in sequence
  // to out
  void read(std::istream & in);
  // Precondition: in is an open istream
  // Postcondition: head points to a new linked-list that contains the
  // characters in in

  void error(const char * s) const
  {std::cerr << "Error: " << s << std::endl; throw 0;}
  // Precondition: s is c-string
  // Postcondition: c-string s is printed to standard error (cerr)
  static int getMemoryAllocation()
  {return NumAllocations;}
  // Precondition: none
  // Postcondition: Return value is the number of nodes allocated

private:

  ListNode * head;              // points to first node of linked-list
  static int NumAllocations;    // number of nodes allocated

  int numChars(const char * s) const;
  void construct_list(const char * s);
  void destroy_list();
  void delete_node(ListNode * node);
  ListNode * create_node(char s, ListNode * next = NULL) const;
  char * constructCstring(const ListNode * head);
  void con(const MyString & s);
  void de();
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
