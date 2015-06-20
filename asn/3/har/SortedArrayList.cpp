// Course: CS 14 Spring 2012
// 
// First Name: Samuel
// Last Name: Villarreal
// UCR Username: svill017
// UCR Email Address: svill017@ucr.edu
// 
// Lecture Section: 001
// Lab Section: 021
// TA: Krystof Litomisky
// 
// Assignment: assignment 3
// 
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
// 
// ===========================================================================

#include "Timer.h"
#include "SortedArrayList.h"

using namespace std;

SortedArrayList::SortedArrayList(size_t capacity)
: SortedList(), buf(NULL), capacity(capacity), size(0)
{create_array(capacity);}

SortedArrayList::SortedArrayList(const SortedArrayList & source)
: SortedList(), buf(NULL), capacity(source.capacity), size(source.size)
{
  create_array(capacity);
  for(size_t i = 0; i < size; ++i) buf[i] = source.buf[i];
}

SortedArrayList::~SortedArrayList() {destroy_array();}

SortedArrayList & SortedArrayList::operator =(const SortedArrayList & rhs)
{
  destroy_array();
  capacity = rhs.capacity;
  size = rhs.size;
  create_array(capacity);
  for(size_t i = 0; i != size; ++i) buf[i] = rhs.buf[i];
  return *this;
}

void SortedArrayList::insert(const string & word)
{
  if(isFull())
  {
    cerr << "error is full";
    return;
  }
  else if(isEmpty())
  {
    buf[0] = word;
    size++;
  }
  else 
  {
    int temp = size-1;
    buf[size] = word;
    while( temp >= 0 && !lessThan(buf[temp+1],buf[temp]))
    {
      buf[temp+1] = buf[temp];
      buf[temp] = word;
      temp--;
    }
    size++;
    return;
  }
  
}
    

bool SortedArrayList::find(const string & word) const
{
  unsigned i = 0;
  while(i< size)
  {
    if(buf[i] == word) return true;
    i++;
  }
  return false;
  // *** REPLACE WITH YOUR IMPLEMENTATION ***
}

void SortedArrayList::remove(const string & word)
{
  if(!find(word)) return;
  unsigned i =0;
    while( buf[i] != word)
    {
      i++;
    }
    while(i < size)
    {
      buf[i] = buf[i+1];
      i++;
    }
    buf[i] = "";
    size--;
// *** REPLACE WITH YOUR IMPLEMENTATION ***
}

void SortedArrayList::create_array(size_t capacity)
{
  if(buf != NULL) destroy_array();
  if(capacity > 0) buf = new string[capacity];
  NumAllocations += capacity;
}

void SortedArrayList::destroy_array()
{
  if(buf != NULL) delete[] buf;
  NumAllocations -= capacity;
  buf = NULL;
}

int SortedArrayList::indexOf(const string & word) const
{for(int i = 0; i < int(size); ++i) if(buf[i] == word) return i; return -1;}
