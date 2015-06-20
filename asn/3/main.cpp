#include <iostream>
#include "SortedList.h"
#include "SortedArrayList.h"
#include "SortedLinkedList.h"

using namespace std;

int main()
{
  string word("hello");
SortedList * list; // pointer to base class can point to any derived class
list = new SortedArrayList;
list->insert(word);
list->find(word);
list->insert(word);
list->batch(&SortedList::insert, string("ran.txt"));
list->find("hhhhhh");
list->batch(&SortedList::remove, string("ran.txt"));
//list = new SortedLinkedList;
//list->insert(word);
//list->find(word);
//list->insert(word);
//list->batch(&SortedList::insert, string("random.txt"));
//list->batch(&SortedList::remove, string("random.txt"));
return 0;
}
