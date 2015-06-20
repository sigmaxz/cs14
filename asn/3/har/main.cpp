#include <iostream>
#include <fstream>
#include "SortedArrayListTests.h"
#include "SortedLinkedListTests.h"

using namespace std;

bool batch_test(int test)
{
  size_t size = 1402;
  string * buf = new string[size];
  ifstream in("sorted_short.txt");
  for(size_t i = 0; i != size; ++i) in >> buf[i];
  in.close();

  // array insert
  if(test == 46)
  {
    SortedList * list = new SortedArrayList;
    list->batch(&SortedList::insert, string("random_short.txt"));
    SortedArrayList * p = static_cast<SortedArrayList *>(list);
    for(size_t i = 0; i != size; ++i) if((*p)[i] != buf[i]) return false;
  }
  // array remove
  else if(test == 47)
  {
    SortedList * list = new SortedArrayList;
    list->batch(&SortedList::remove, string("random_short.txt"));
    SortedArrayList * p = static_cast<SortedArrayList *>(list);
    if(p->size_cassej() != 0) return false;
  }
  // linked-list insert
  else if(test == 48)
  {
    SortedList * list = new SortedLinkedList;
    list->batch(&SortedList::insert, string("random_short.txt"));
    SortedLinkedList * p = static_cast<SortedLinkedList *>(list);
    for(size_t i = 0; i != size; ++i) if((*p)[i] != buf[i]) return false;
  }
  // linked-list remove
  else if(test == 49)
  {
    SortedList * list = new SortedLinkedList;
    list->batch(&SortedList::remove, string("random_short.txt"));
    SortedLinkedList * p = static_cast<SortedLinkedList *>(list);
    if(p->size_cassej() != 0) return false;
  }
  else exit(1);
  return true;
}

bool less_than_test(int test)
{
  // equal strings
  if(test == 43)
  {
    string lhs("hello");
    string rhs("Hello");
    if(lessThan(lhs, rhs)) return false;
  }
  // different strings return false
  else if(test == 44)
  {
    string lhs("hello");
    string rhs("helicopter");
    if(lessThan(lhs, rhs)) return false;
  }
  // different strings return true
  else if(test == 45)
  {
    string lhs("helicopter");
    string rhs("hello");
    if(!lessThan(lhs, rhs)) return false;
  }
  else exit(1);
  return true;
}

int main(int argc, char ** argv)
{
  if(argc != 2)
  {cerr << "usage: " << argv[0] << " test_number" << endl; exit(1);}

  int test = atoi(argv[1]);

  ofstream out("result.txt");

  //if(test == 1)
  //{
  //  if(default_constructor_test()) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 2)
  //{
  //  if(single_parameter_constructor_test(0)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 3)
  //{
  //  if(single_parameter_constructor_test(1)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 4)
  //{
  //  if(copy_constructor_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 5)
  //{
  //  if(copy_constructor_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 6)
  //{
  //  if(assignment_operator_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 7)
  //{
  //  if(assignment_operator_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  if(test == 8)
  {
    if(insert_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 9)
  {
    if(insert_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 10)
  {
    if(insert_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 11)
  {
    if(remove_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 12)
  {
    if(remove_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 13)
  {
    if(remove_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 14)
  {
    if(find_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 15)
  {
    if(find_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  //if(test == 16)
  //{
  //  if(isFull_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 17)
  //{
  //  if(isFull_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 18)
  //{
  //  if(isEmpty_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 19)
  //{
  //  if(isEmpty_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  if(test == 20)
  {
    if(timing_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 21)
  {
    if(timing_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 22)
  {
    if(timing_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  //if(test == 23)
  //{
  //  if(linked_list_default_constructor_test()) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 24)
  //{
  //  if(linked_list_copy_constructor_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 25)
  //{
  //  if(linked_list_copy_constructor_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 26)
  //{
  //  if(linked_list_assignment_operator_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 27)
  //{
  //  if(linked_list_assignment_operator_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  if(test == 28)
  {
    if(linked_list_insert_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 29)
  {
    if(linked_list_insert_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 30)
  {
    if(linked_list_insert_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 31)
  {
    if(linked_list_remove_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 32)
  {
    if(linked_list_remove_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 33)
  {
    if(linked_list_remove_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 34)
  {
    if(linked_list_find_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 35)
  {
    if(linked_list_find_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  //if(test == 36)
  //{
  //  if(linked_list_isFull_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 37)
  //{
  //  if(linked_list_isFull_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 38)
  //{
  //  if(linked_list_isEmpty_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  //if(test == 39)
  //{
  //  if(linked_list_isEmpty_test(test)) out << test << endl;
  //  else out << 0 << endl;
  //}

  if(test == 40)
  {
    if(linked_list_timing_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 41)
  {
    if(linked_list_timing_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 42)
  {
    if(linked_list_timing_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 43)
  {
    if(less_than_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 44)
  {
    if(less_than_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 45)
  {
    if(less_than_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 46)
  {
    if(batch_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 47)
  {
    if(batch_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 48)
  {
    if(batch_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 49)
  {
    if(batch_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  return 0;
}
