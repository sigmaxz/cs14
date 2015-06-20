#include <iostream>
#include <fstream>
#include "Timer.h"
#include "SortedLinkedList.h"

using namespace std;

struct test_23
{
  bool operator()()
  {
    SortedLinkedList list;
    if(list.head != NULL) return false;
    return true;
  }
} linked_list_default_constructor_test;

struct test_24_25
{
  bool operator()(int test)
  {
    if(test == 24)
    {
      SortedLinkedList list;
      list.head = NULL;
      SortedLinkedList copy(list);
      if(copy.head != list.head) return false;
    }
    else if(test == 25)
    {
      char * test = new char[5]; test[0] = 't'; test[1] = 'e'; test[2] = 's';
      test[3] = 't'; test[4] = '\0';
      SortedLinkedList list;
      list.head = new ListNode;
      list.head->word = test;
      list.head->next = NULL;
      SortedLinkedList copy(list);
      if(copy.head->word != list.head->word) return false;
      if(copy.head->next != list.head->next) return false;
    }
    else exit(1);
    return true;
  }
} linked_list_copy_constructor_test;

struct test_26_27
{
  bool operator()(int test)
  {
    if(test == 26)
    {
      SortedLinkedList list;
      list.head = NULL;
      SortedLinkedList copy;
      copy = list;
      if(copy.head != NULL) return false;
    }
    else if(test == 27)
    {
      SortedLinkedList list;
      list.head = new ListNode;
      list.head->word = "test";
      list.head->next = NULL;
      SortedLinkedList copy;
      copy = list;
      if(copy.head->word != list.head->word) return false;
      if(copy.head->next != list.head->next) return false;
    }
    else exit(1);
    return true;
  }
} linked_list_assignment_operator_test;

struct test_28_30
{
  bool operator()(int test)
  {
    SortedLinkedList list;
    list.head = new ListNode;
    list.head->word = "Airplane";
    ListNode * p = list.head; p->next = new ListNode;
    p = p->next;
    p->word = "atom"; p->next = new ListNode;
    p = p->next;
    p->word = "yoyo"; p->next = NULL;
    if(test == 28)
    {
      list.insert(string("actor"));
      p = list.head;
      if(p->word != "actor") return false;
      p = p->next;
      if(p->word != "Airplane") return false;
      p = p->next;
      if(p->word != "atom") return false;
      p = p->next;
      if(p->word != "yoyo") return false;
      if(p->next != NULL) return false;
    }
    else if(test == 29)
    {
      list.insert(string("ball"));
      p = list.head;
      if(p->word != "Airplane") return false;
      p = p->next;
      if(p->word != "atom") return false;
      p = p->next;
      if(p->word != "ball") return false;
      p = p->next;
      if(p->word != "yoyo") return false;
      if(p->next != NULL) return false;
    }
    else if(test == 30)
    {
      list.insert(string("zebra"));
      p = list.head;
      if(p->word != "Airplane") return false;
      p = p->next;
      if(p->word != "atom") return false;
      p = p->next;
      if(p->word != "yoyo") return false;
      p = p->next;
      if(p->word != "zebra") return false;
      if(p->next != NULL) return false;
    }
    else exit(1);
    return true;
  }
} linked_list_insert_test;

struct test_31_33
{
  bool operator()(int test)
  {
    SortedLinkedList list;
    list.head = new ListNode;
    list.head->word = "Airplane";
    ListNode * p = list.head; p->next = new ListNode;
    p = p->next;
    p->word = "atom"; p->next = new ListNode;
    p = p->next;
    p->word = "yoyo"; p->next = NULL;
    if(test == 31)
    {
      list.remove(string("Airplane"));
      p = list.head;
      if(p->word != "atom") return false;
      p = p->next;
      if(p->word != "yoyo") return false;
      if(p->next != NULL) return false;
    }
    else if(test == 32)
    {
      list.remove(string("atom"));
      p = list.head;
      if(p->word != "Airplane") return false;
      p = p->next;
      if(p->word != "yoyo") return false;
      if(p->next != NULL) return false;
    }
    else if(test == 33)
    {
      list.remove(string("yoyo"));
      p = list.head;
      if(p->word != "Airplane") return false;
      p = p->next;
      if(p->word != "atom") return false;
      if(p->next != NULL) return false;
    }
    else exit(1);
    return true;
  }
} linked_list_remove_test;

struct test_34_35
{
  bool operator()(int test)
  {
    SortedLinkedList list;
    list.head = new ListNode;
    list.head->word = "Airplane";
    ListNode * p = list.head; p->next = new ListNode;
    p = p->next;
    p->word = "atom"; p->next = new ListNode;
    p = p->next;
    p->word = "yoyo"; p->next = NULL;
    if(test == 34) if(!list.find(string("atom"))) return false;
    else if(test == 35) if(list.find(string("zebra"))) return false;
    else exit(1);
    return true;
  }
} linked_list_find_test;

struct test_36_37
{
  bool operator()(int test)
  {
    SortedLinkedList list;
    list.head = new ListNode;
    list.head->word = "Airplane";
    ListNode * p = list.head; p->next = new ListNode;
    p = p->next;
    p->word = "atom"; p->next = new ListNode;
    p = p->next;
    p->word = "yoyo"; p->next = NULL;
    if(test == 36) {if(list.isFull()) return false;}
    else if(test == 37) {list.head = NULL; if(list.isFull()) return false;}
    else exit(1);
    return true;
  }
} linked_list_isFull_test;

struct test_38_39
{
  bool operator()(int test)
  {
    SortedLinkedList list;
    list.head = new ListNode;
    list.head->word = "Airplane";
    ListNode * p = list.head; p->next = new ListNode;
    p = p->next;
    p->word = "atom"; p->next = new ListNode;
    p = p->next;
    p->word = "yoyo"; p->next = NULL;
    if(test == 38) {if(list.isEmpty()) return false;}
    else if(test == 39) {list.head = NULL; if(!list.isEmpty()) return false;}
    else exit(1);
    return true;
  }
} linked_list_isEmpty_test;

struct test_40_42
{
  bool operator()(int test)
  {
    const int LENGTH = 512;
    const double TIMEOUT = 600; // 10 minutes
    char * word = new char[LENGTH];
    double time;
    Timer timer;
    ifstream in;
    SortedLinkedList list;
    list.head = NULL;
    if(test == 40)
    {
      in.open("random_short.txt");
      while(!in.eof())
      {
        in.getline(word, LENGTH);
        timer.start();
        list.insert(string(word));
        timer.stop();
        cerr << timer.cumulativeTime();
        if(timer.cumulativeTime() > TIMEOUT) return false;
      }
      in.close();
      time = timer.cumulativeTime();
      cout << "linked-list insert " << time << endl;
    }
    else if(test == 41)
    {
      in.open("sorted_short.txt");
      list.head = new ListNode;
      ListNode * p = list.head;
      in.getline(word, LENGTH);
      p->word = string(word);
      do
      {
        p->next = new ListNode;
        p = p->next;
        p->word = string(word);
        in.getline(word, LENGTH);
      }
      while(!in.eof());
      p->next = NULL;
      in.close();
      in.clear();
      in.open("random_short.txt");
      in.getline(word, LENGTH);
      do
      {
        timer.start();
        list.find(string(word));
        timer.stop();
        if(timer.cumulativeTime() > TIMEOUT) return false;
        in.getline(word, LENGTH);
      }
      while(!in.eof());
      in.close();
      time = timer.cumulativeTime();
      cout << "linked-list find " << time << endl;
    }
    else if(test == 42)
    {
      in.open("sorted_short.txt");
      list.head = new ListNode;
      ListNode * p = list.head;
      in.getline(word, LENGTH);
      p->word = string(word);
      do
      {
        p->next = new ListNode;
        p = p->next;
        p->word = string(word);
        in.getline(word, LENGTH);
      }
      while(!in.eof());
      p->next = NULL;
      in.close();
      in.clear();
      in.open("random_short.txt");
      in.getline(word, LENGTH);
      do
      {
        timer.start();
        list.remove(string(word));
        timer.stop();
        if(timer.cumulativeTime() > TIMEOUT) return false;
        in.getline(word, LENGTH);
      }
      while(!in.eof());
      in.close();
      time = timer.cumulativeTime();
      cout << "linked-list remove " << time << endl;
    }
    else exit(1);
    return true;
  }
} linked_list_timing_test;

//struct linked_list_sort_t
//{
//  void operator()()
//  {
//    char word[512];
//    ifstream in("random.txt");
//    SortedLinkedList list;
//    in.getline(word, 512);
//    while(!in.eof())
//    {
//      list.insert(string(word));
//      in.getline(word, 512);
//    }
//    in.close();
//    ofstream out("sorted.txt");
//    for(ListNode * p = list.head; p != NULL; p = p->next)
//      out << p->word << endl;
//    out.close();
//  }
//} linked_list_sort;
