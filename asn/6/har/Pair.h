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
#ifndef PAIR_H
#define PAIR_H

#include <string>

template<typename HashedObj, typename Object>
class Pair
{
public:
  Pair() {}
  Pair(const HashedObj & key, const Object & def) : key(key), def(def) {}

  bool operator ==(const Pair<HashedObj, Object> & rhs) const
  {return key == rhs.key;}

  bool operator !=(const Pair<HashedObj, Object> & rhs) const
  {return !(*this == rhs);}

  HashedObj get_key() const {return key;}

  const HashedObj & get_def() const {return def;}

private:
  HashedObj key;
  Object    def;
};

int hash(const Pair<std::string, std::string> & key);

#endif
