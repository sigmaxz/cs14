#include <iostream>
#include <fstream>
#include "Timer.h"
#include "SortedArrayList.h"

using namespace std;

struct test_1
{
  bool operator()()
  {
    SortedArrayList list;
    if(list.size != 0) return false;
    if(list.capacity != CAPACITY) return false;
    for(size_t i = 0; i != CAPACITY; ++i) if(list.buf[i] != "") return false;
    return true;
  }
} default_constructor_test;

struct test_2_3
{
  bool operator()(size_t capacity)
  {
    SortedArrayList list(capacity);
    if(list.size != 0) return false;
    if(list.capacity != capacity) return false;
    for(size_t i = 0; i != capacity; ++i) if(list.buf[i] != "") return false;
    return true;
  }
} single_parameter_constructor_test;

struct test_4_5
{
  bool operator()(int test)
  {
    if(test == 4)
    {
      SortedArrayList list;
      list.buf = NULL;
      list.capacity = 0;
      list.size = 0;
      SortedArrayList copy(list);
      if(copy.size != list.size) return false;
      if(copy.capacity != list.capacity) return false;
      if(copy.buf != NULL) return false;
    }
    else if(test == 5)
    {
      SortedArrayList list;
      list.buf = new string[5];
      list.buf[0] = "test";
      list.capacity = 5;
      list.size = 1;
      SortedArrayList copy(list);
      if(copy.size != list.size) return false;
      if(copy.capacity != list.capacity) return false;
      if(copy.buf[0] != "test") return false;
      for(size_t i = 1; i != 5; ++i) if(copy.buf[i] != "") return false;
    }
    else exit(1);
    return true;
  }
} copy_constructor_test;

struct test_6_7
{
  bool operator()(int test)
  {
    if(test == 6)
    {
      SortedArrayList list;
      list.buf = NULL;
      list.capacity = 0;
      list.size = 0;
      SortedArrayList copy;
      copy = list;
      if(copy.size != list.size) return false;
      if(copy.capacity != list.capacity) return false;
      if(copy.buf != NULL) return false;
    }
    else if(test == 7)
    {
      SortedArrayList list;
      list.buf = new string[5];
      list.buf[0] = "test";
      list.capacity = 5;
      list.size = 1;
      SortedArrayList copy;
      copy = list;
      if(copy.size != list.size) return false;
      if(copy.capacity != list.capacity) return false;
      if(copy.buf[0] != "test") return false;
      for(size_t i = 1; i != 5; ++i) if(copy.buf[i] != "") return false;
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
      SortedArrayList list;
      list.buf = new string[5];
      list.capacity = 5;
      list.buf[0] = "Airplane";
      list.buf[1] = "atom";
      list.buf[2] = "yoyo";
      list.size = 3;
      list.insert(string("actor"));
      if(list.size != 4) return false;
      if(list.buf[0] != "actor") return false;
      if(list.buf[1] != "Airplane") return false;
      if(list.buf[2] != "atom") return false;
      if(list.buf[3] != "yoyo") return false;
      for(size_t i = 4; i != 5; ++i) if(list.buf[i] != "") return false;
    }
    else if(test == 9)
    {
      SortedArrayList list;
      list.buf = new string[5];
      list.capacity = 5;
      list.buf[0] = "Airplane";
      list.buf[1] = "atom";
      list.buf[2] = "yoyo";
      list.size = 3;
      list.insert(string("ball"));
      if(list.size != 4) return false;
      if(list.buf[0] != "Airplane") return false;
      if(list.buf[1] != "atom") return false;
      if(list.buf[2] != "ball") return false;
      if(list.buf[3] != "yoyo") return false;
      for(size_t i = 4; i != 5; ++i) if(list.buf[i] != "") return false;
    }
    else if(test == 10)
    {
      SortedArrayList list;
      list.buf = new string[5];
      list.capacity = 5;
      list.buf[0] = "Airplane";
      list.buf[1] = "atom";
      list.buf[2] = "yoyo";
      list.size = 3;
      list.insert(string("zebra"));
      if(list.size != 4) return false;
      if(list.buf[0] != "Airplane") return false;
      if(list.buf[1] != "atom") return false;
      if(list.buf[2] != "yoyo") return false;
      if(list.buf[3] != "zebra") return false;
      for(size_t i = 4; i != 5; ++i) if(list.buf[i] != "") return false;
    }
    else exit(1);
    return true;
  }
} insert_test;

struct test_11_13
{
  bool operator()(int test)
  {
    if(test == 11)
    {
      SortedArrayList list;
      list.buf = new string[5];
      list.capacity = 5;
      list.buf[0] = "Airplane";
      list.buf[1] = "atom";
      list.buf[2] = "yoyo";
      list.size = 3;
      list.remove(string("Airplane"));
      if(list.size != 2) return false;
      if(list.buf[0] != "atom") return false;
      if(list.buf[1] != "yoyo") return false;
      for(size_t i = 2; i != 5; ++i) if(list.buf[i] != "") return false;
    }
    else if(test == 12)
    {
      SortedArrayList list;
      list.buf = new string[5];
      list.capacity = 5;
      list.buf[0] = "Airplane";
      list.buf[1] = "atom";
      list.buf[2] = "yoyo";
      list.size = 3;
      list.remove(string("atom"));
      if(list.size != 2) return false;
      if(list.buf[0] != "Airplane") return false;
      if(list.buf[1] != "yoyo") return false;
      for(size_t i = 2; i != 5; ++i) if(list.buf[i] != "") return false;
    }
    else if(test == 13)
    {
      SortedArrayList list;
      list.buf = new string[5];
      list.capacity = 5;
      list.buf[0] = "Airplane";
      list.buf[1] = "atom";
      list.buf[2] = "yoyo";
      list.size = 3;
      list.remove(string("yoyo"));
      if(list.size != 2) return false;
      if(list.buf[0] != "Airplane") return false;
      if(list.buf[1] != "atom") return false;
      for(size_t i = 2; i != 5; ++i) if(list.buf[i] != "") return false;
    }
    else exit(1);
    return true;
  }
} remove_test;

struct test_14_15
{
  bool operator()(int test)
  {
    SortedArrayList list;
    list.buf = new string[5];
    list.capacity = 5;
    list.buf[0] = "Airplane";
    list.buf[1] = "atom";
    list.buf[2] = "yoyo";
    list.size = 3;
    if(test == 14) if(!list.find(string("atom"))) return false;
    else if(test == 15) if(list.find(string("zebra"))) return false;
    else exit(1);
    return true;
  }
} find_test;

struct test_16_17
{
  bool operator()(int test)
  {
    SortedArrayList list;
    list.buf = new string[5];
    list.capacity = 5;
    if(test == 16) {list.size = 4; if(list.isFull()) return false;}
    else if(test == 17) {list.size = 5; if(!list.isFull()) return false;}
    else exit(1);
    return true;
  }
} isFull_test;

struct test_18_19
{
  bool operator()(int test)
  {
    SortedArrayList list;
    list.buf = new string[5];
    list.capacity = 5;
    if(test == 18) {list.size = 4; if(list.isEmpty()) return false;}
    else if(test == 19) {list.size = 0; if(!list.isEmpty()) return false;}
    else exit(1);
    return true;
  }
} isEmpty_test;

struct test_20_22
{
  bool operator()(int test)
  {
    const int LENGTH = 512;
    const double TIMEOUT = 600; // 10 minutes
    char * word = new char[LENGTH];
    double time;
    Timer timer;
    ifstream in;
    SortedArrayList list;
    list.buf = new string[CAPACITY];
    list.capacity = CAPACITY;
    list.size = 0;
    if(test == 20)
    {
      in.open("random_short.txt");
      while(!in.eof())
      {
        in.getline(word, LENGTH);
        timer.start();
        list.insert(string(word));
        timer.stop();
        if(timer.cumulativeTime() > TIMEOUT) return false;
      }
      in.close();
      time = timer.cumulativeTime();
      cout << "array insert " << time << endl;
    }
    else if(test == 21)
    {
      size_t i = 0;
      in.open("sorted_short.txt");
      while(!in.eof())
      {
        in.getline(word, LENGTH);
        list.buf[i++] = string(word);
        ++list.size;
      }
      in.close();
      in.clear();
      in.open("random_short.txt");
      while(!in.eof())
      {
        in.getline(word, LENGTH);
        timer.start();
        list.find(string(word));
        timer.stop();
        if(timer.cumulativeTime() > TIMEOUT) return false;
      }
      in.close();
      time = timer.cumulativeTime();
      cout << "array find " << time << endl;
    }
    else if(test == 22)
    {
      size_t i = 0;
      in.open("sorted_short.txt");
      while(!in.eof())
      {
        in.getline(word, LENGTH);
        list.buf[i++] = string(word);
        ++list.size;
      }
      in.close();
      in.clear();
      in.open("random_short.txt");
      while(!in.eof())
      {
        in.getline(word, LENGTH);
        timer.start();
        list.remove(string(word));
        timer.stop();
        if(timer.cumulativeTime() > TIMEOUT) return false;
      }
      in.close();
      time = timer.cumulativeTime();
      cout << "array remove " << time << endl;
    }
    else exit(1);
    return true;
  }
} timing_test;

//struct sort_t
//{
//  void operator()()
//  {
//    char word[512];
//    ifstream in("random.txt");
//    SortedArrayList list;
//    in.getline(word, 512);
//    while(!in.eof())
//    {
//      list.insert(string(word));
//      in.getline(word, 512);
//    }
//    in.close();
//    ofstream out("sorted.txt");
//    for(size_t i = 0; i != list.size; ++i) out << list.buf[i] << endl;
//    out.close();
//  }
//} sort;
