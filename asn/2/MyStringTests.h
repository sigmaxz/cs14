#include <fstream>
#include "MyString.h"

char * test_string(int length)
{
  char * s = new char[length + 1];
  for(char i = 0; i != length; ++i) s[i] = 'a' + i; s[length] = '\0';
  return s;
}

struct test_1
{
  bool operator()(int)
  {
    MyString string;
    if(string.head == NULL) return true;
    else return false;
  }
} default_constructor_test;

struct test_2
{
  bool operator()(int)
  {
    const int LENGTH = 4;
    char * test = test_string(LENGTH);
    MyString string(test);
    ListNode * cursor = string.head;
    for(int i = 0; i != LENGTH; ++i)
    {
      if(cursor->data != test[i]) return false;
      cursor = cursor->next;
    }
    if(cursor != NULL) return false;
    return true;
  }
} single_parameter_constructor_test;

struct test_3_4
{
  bool operator()(int test)
  {
    if(test == 3)
    {
      MyString string;
      MyString copy = string;
      if(copy.head != NULL) return false;
    }
    else if(test == 4)
    {
      MyString string;
      string.head = new ListNode;
      MyString::NumAllocations++;
      string.head->data = 'a';
      string.head->next = new ListNode;
      MyString::NumAllocations++;
      string.head->next->data = 'b';
      string.head->next->next = NULL;
      MyString copy = string;
      ListNode * cursor = copy.head;
      if(cursor->data != 'a') return false;
      cursor = cursor->next;
      if(cursor->data != 'b') return false;
      cursor = cursor->next;
      if(cursor != NULL) return false;
    }
    else exit(1);
    return true;
  }
} copy_constructor_test;

struct test_5
{
  bool operator()(int)
  {
    ListNode * a;
    ListNode * b;
    {
      MyString string;
      string.head = new ListNode;
      MyString::NumAllocations++;
      string.head->data = 'a';
      string.head->next = new ListNode;
      MyString::NumAllocations++;
      string.head->next->data = 'b';
      string.head->next->next = NULL;
      a = string.head;
      b = string.head->next;
    }
    if(a != NULL && a->data == 'a') return false;
    if(b != NULL && b->data == 'b') return false;
    return true;
  }
} destructor_test;

struct test_6_7
{
  bool operator()(int test)
  {
    if(test == 6)
    {
      MyString string;
      string.head = NULL;
      MyString copy;
      copy = string;
      if(copy.head != NULL) return false;
      return true;
    }
    else if(test == 7)
    {
      MyString string;
      string.head = new ListNode;
      MyString::NumAllocations++;
      string.head->data = 'a';
      string.head->next = new ListNode;
      MyString::NumAllocations++;
      string.head->next->data = 'b';
      string.head->next->next = NULL;
      MyString copy;
      copy = string;
      ListNode * cursor = copy.head;
      if(cursor->data != 'a') return false;
      cursor = cursor->next;
      if(cursor->data != 'b') return false;
      cursor = cursor->next;
      if(cursor != NULL) return false;
    }
    else exit(1);
    return true;
  }
} assignment_operator_test;

struct test_8_10
{
  bool operator()(int test)
  {
    if(test == 8)
    {
      MyString string;
      string.head = NULL;
      try
      {
        char c = string[-1];
        return false;
      }
      catch(int) {}
    }
    else if(test == 9)
    {
      MyString string;
      string.head = new ListNode;
      MyString::NumAllocations++;
      string.head->data = 'a';
      string.head->next = new ListNode;
      MyString::NumAllocations++;
      string.head->next->data = 'b';
      string.head->next->next = NULL;
      try
      {
        char c = string[1];
        if(c != 'b') return false;
      }
      catch(int) {return false;}
    }
    else if(test == 10)
    {
      MyString string;
      string.head = NULL;
      try
      {
        char c = string[0];
        return false;
      }
      catch(int) {}
    }
    else exit(1);
    return true;
  }
} index_operator_test;

struct test_11_12
{
  bool operator()(int test)
  {
    if(test == 11)
    {
      MyString string;
      string.head = NULL;
      if(string.length() != 0) return false;
    }
    else if(test == 12)
    {
      MyString string;
      string.head = new ListNode;
      MyString::NumAllocations++;
      string.head->data = 'a';
      string.head->next = new ListNode;
      MyString::NumAllocations++;
      string.head->next->data = 'b';
      string.head->next->next = NULL;
      if(string.length() != 2) return false;
    }
    else exit(1);
    return true;
  }
} length_test;

struct test_13_15
{
  bool operator()(int test)
  {
    if(test == 13)
    {
      MyString string;
      string.head = NULL;
      try
      {
        int i = string.indexOf('z');
        return false;
      }
      catch(int) {}
    }
    else if(test == 14)
    {
      MyString string;
      string.head = new ListNode;
      MyString::NumAllocations++;
      string.head->data = 'a';
      string.head->next = new ListNode;
      MyString::NumAllocations++;
      string.head->next->data = 'b';
      string.head->next->next = NULL;
      try
      {
        int i = string.indexOf('z');
        return false;
      }
      catch(int) {}
    }
    else if(test == 15)
    {
      MyString string;
      string.head = new ListNode;
      MyString::NumAllocations++;
      string.head->data = 'a';
      string.head->next = new ListNode;
      MyString::NumAllocations++;
      string.head->next->data = 'b';
      string.head->next->next = NULL;
      try
      {
        int i = string.indexOf('b');
        if(i != 1) return false;
      }
      catch(int) {return false;}
    }
    else exit(1);
    return true;
  }
} indexOf_test;

struct test_16_20
{
  bool operator()(int test)
  {
    if(test == 16)
    {
      MyString a;
      a.head = NULL;
      MyString b;
      b.head = NULL;
      if(!(a == b)) return false;
    }
    else if(test == 17)
    {
      MyString a;
      a.head = new ListNode;
      MyString::NumAllocations++;
      a.head->data = 'a';
      a.head->next = NULL;
      MyString b;
      b.head = NULL;
      if(a == b) return false;
    }
    else if(test == 18)
    {
      MyString a;
      a.head = new ListNode;
      MyString::NumAllocations++;
      a.head->data = 'a';
      a.head->next = NULL;
      MyString b;
      b.head = NULL;
      if(b == a) return false;
    }
    else if(test == 19)
    {
      MyString a;
      a.head = new ListNode;
      MyString::NumAllocations++;
      a.head->data = 'a';
      a.head->next = NULL;
      MyString b;
      b.head = new ListNode;
      MyString::NumAllocations++;
      b.head->data = 'b';
      b.head->next = NULL;
      if(a == b) return false;
    }
    else if(test == 20)
    {
      MyString a;
      a.head = new ListNode;
      MyString::NumAllocations++;
      a.head->data = 'a';
      a.head->next = NULL;
      MyString b;
      b.head = new ListNode;
      MyString::NumAllocations++;
      b.head->data = 'a';
      b.head->next = NULL;
      if(!(a == b)) return false;
    }
    else exit(1);
    return true;
  }
} operator_equals_test;

struct test_21_24
{
  bool operator()(int test)
  {
    if(test == 21)
    {
      MyString a;
      a.head = NULL;
      MyString b;
      b.head = NULL;
      ListNode * p = (a + b).head;
      if(p != NULL) return false;
    }
    else if(test == 22)
    {
      MyString a;
      a.head = NULL;
      MyString b;
      b.head = new ListNode;
      MyString::NumAllocations++;
      b.head->data = 'b';
      b.head->next = NULL;
      ListNode node;
      node.data = (a + b).head->data;
      node.next = (a + b).head->next;
      if(node.data != 'b') return false;
      if(node.next != NULL) return false;
    }
    else if(test == 23)
    {
      MyString a;
      a.head = NULL;
      MyString b;
      b.head = new ListNode;
      MyString::NumAllocations++;
      b.head->data = 'b';
      b.head->next = NULL;
      ListNode node;
      node.data = (b + a).head->data;
      node.next = (b + a).head->next;
      if(node.data != 'b') return false;
      if(node.next != NULL) return false;
    }
    else if(test == 24)
    {
      MyString a;
      a.head = new ListNode;
      MyString::NumAllocations++;
      a.head->data = 'a';
      a.head->next = NULL;
      MyString b;
      b.head = new ListNode;
      MyString::NumAllocations++;
      b.head->data = 'b';
      b.head->next = NULL;
      ListNode node_a;
      node_a.data = (a + b).head->data;
      node_a.next = (a + b).head->next;
      ListNode node_b;
      node_b.data = (a + b).head->next->data;
      node_b.next = (a + b).head->next->next;
      if(node_a.data != 'a') return false;
      if(node_a.next == NULL) return false;
      if(node_b.data != 'b') return false;
      if(node_b.next != NULL) return false;
    }
    else exit(1);
    return true;
  }
} operator_plus_test;

struct test_25_28
{
  bool operator()(int test)
  {
    if(test == 25)
    {
      MyString a;
      a.head = NULL;
      MyString b;
      b.head = NULL;
      a += b;
      if(a.head != NULL) return false;
    }
    else if(test == 26)
    {
      MyString a;
      a.head = NULL;
      MyString b;
      b.head = new ListNode;
      MyString::NumAllocations++;
      b.head->data = 'b';
      b.head->next = NULL;
      a += b;
      if(a.head->data != 'b') return false;
      if(a.head->next != NULL) return false;
    }
    else if(test == 27)
    {
      MyString a;
      a.head = NULL;
      MyString b;
      b.head = new ListNode;
      MyString::NumAllocations++;
      b.head->data = 'b';
      b.head->next = NULL;
      b += a;
      if(b.head->data != 'b') return false;
      if(b.head->next != NULL) return false;
    }
    else if(test == 28)
    {
      MyString a;
      a.head = new ListNode;
      MyString::NumAllocations++;
      a.head->data = 'a';
      a.head->next = NULL;
      MyString b;
      b.head = new ListNode;
      MyString::NumAllocations++;
      b.head->data = 'b';
      b.head->next = NULL;
      a += b;
      if(a.head->data != 'a') return false;
      if(a.head->next == NULL) return false;
      if(a.head->next->data != 'b') return false;
      if(a.head->next->next != NULL) return false;
    }
    else exit(1);
    return true;
  }
} operator_plus_equals_test;

struct test_29_32
{
  bool operator()(int test)
  {
    if(test == 29)
    {
      MyString string;
      string.head = NULL;
      ListNode * node = (string.reverse()).head;
      if(node != NULL) return false;
    }
    else if(test == 30)
    {
      MyString string;
      string.head = new ListNode;
      MyString::NumAllocations++;
      string.head->data = 'a';
      string.head->next = NULL;
      ListNode node;
      node.data = (string.reverse()).head->data;
      node.next = (string.reverse()).head->next;
      if(node.data != 'a') return false;
      if(node.next != NULL) return false;
    }
    else if(test == 31)
    {
      MyString string;
      string.head = new ListNode;
      MyString::NumAllocations++;
      string.head->data = 'a';
      string.head->next = new ListNode;
      MyString::NumAllocations++;
      string.head->next->data = 'b';
      string.head->next->next = NULL;
      ListNode b;
      b.data = (string.reverse()).head->data;
      b.next = (string.reverse()).head->next;
      ListNode a;
      a.data = (string.reverse()).head->next->data;
      a.next = (string.reverse()).head->next->next;
      if(b.data != 'b') return false;
      if(b.next == NULL) return false;
      if(a.data != 'a') return false;
      if(a.next != NULL) return false;
    }
    else if(test == 32)
    {
      MyString string;
      string.head = new ListNode;
      MyString::NumAllocations++;
      string.head->data = 'a';
      string.head->next = new ListNode;
      MyString::NumAllocations++;
      string.head->next->data = 'b';
      string.head->next->next = new ListNode;
      MyString::NumAllocations++;
      string.head->next->next->data = 'c';
      string.head->next->next->next = NULL;
      ListNode c;
      c.data = (string.reverse()).head->data;
      c.next = (string.reverse()).head->next;
      ListNode b;
      b.data = (string.reverse()).head->next->data;
      b.next = (string.reverse()).head->next->next;
      ListNode a;
      a.data = (string.reverse()).head->next->next->data;
      a.next = (string.reverse()).head->next->next->next;
      if(c.data != 'c') return false;
      if(c.next == NULL) return false;
      if(b.data != 'b') return false;
      if(b.next == NULL) return false;
      if(a.data != 'a') return false;
      if(a.next != NULL) return false;
    }
    else exit(1);
    return true;
  }
} reverse_test;

struct test_33
{
  bool operator()(int)
  {
    const int LENGTH = 512;
    char test[LENGTH];
    std::ifstream in("Read.txt");
    in >> test;
    in.close();
    MyString string;
    string.head = NULL;
    in.open("Read.txt");
    string.read(in);
    in.close();
    ListNode * cursor = string.head;
    for(int i = 0; test[i] != '\0'; ++i)
    {
      if(cursor->data != test[i]) return false;
      cursor = cursor->next;
    }
    if(cursor != NULL) return false;
    return true;
  }
} read_test;

struct test_34
{
  bool operator()(int)
  {
    MyString string;
    string.head = new ListNode;
    MyString::NumAllocations++;
    string.head->data = 'P';
    string.head->next = new ListNode;
    MyString::NumAllocations++;
    string.head->next->data = 'r';
    string.head->next->next = new ListNode;
    MyString::NumAllocations++;
    string.head->next->next->data = 'i';
    string.head->next->next->next = new ListNode;
    MyString::NumAllocations++;
    string.head->next->next->next->data = 'n';
    string.head->next->next->next->next = new ListNode;
    MyString::NumAllocations++;
    string.head->next->next->next->next->data = 't';
    string.head->next->next->next->next->next = NULL;
    std::ofstream out("Print.txt");
    string.print(out);
    out.close();
    std::ifstream in("Print.txt");
    const int LENGTH = 512;
    char test[LENGTH];
    in >> test;
    in.close();
    int i = 0;
    for(ListNode * cursor = string.head; cursor != 0; cursor = cursor->next)
      if(test[i++] != cursor->data) return false;
    return true;
  }
} print_test;
