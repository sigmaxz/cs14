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
// Assignment: assignment 6
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================================
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Pair.h"
#include "HashTable.h"

template<typename HashedObj, typename Object>
class Dictionary
{
public:
  Dictionary() : items(HashTable<Pair<HashedObj, Object> >()) {}

  void insert(const HashedObj & key, const Object & definition)
  // Precondition: none
  // Postcondition: Pair (key,definition) is inserted into hash table items
  {
    Pair<HashedObj,Object> temp(key,definition);
    items.insert(temp);
  }
    
  void remove(const HashedObj & key)
  {
    Pair<HashedObj,Object> temp(key,Object());
    items.remove(temp);
  }

  const Object & lookup(const HashedObj & key) const
  // Precondition: none
  // Postcondition: Return value is definition corresponding to key
  {
    Pair<HashedObj,Object> a(key,Object());
    a = items.at(a);
    return a.get_def();
  }

  bool is_empty() const
  // Precondition: none
  // Postcondition: Return value is true if hash table items is empty
  {
    return items.is_empty();
  }

  void make_empty()
  // Precondition: none
  // Postcondition: Hash table items has no items
  {
    items.make_empty();
  }
  
  void print(std::ostream & out) const
  {
    items.print(out);
  }

private:
  HashTable<Pair<HashedObj, Object> > items;
};

#endif
