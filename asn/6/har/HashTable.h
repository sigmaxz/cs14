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
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <vector>

int next_prime(int n);

struct NotFoundException
{
  NotFoundException() {}
  std::string what() const {return "error: item not found";}
};

template<typename HashedObj>
class HashTable
{
public:
  explicit HashTable(int size = 3) : array(next_prime(size)) {make_empty();}

  bool contains(const HashedObj & x) const {return is_active(find_pos(x));}

  void make_empty()
  {
    current_size = 0;
    for(int i = 0; i < (int)array.size(); ++i) array[i].info = EMPTY;
  }

  bool insert(const HashedObj & x)
  {
    int current_pos = find_pos(x);
    if(is_active(current_pos)) return false;
    array[current_pos] = HashEntry(x, ACTIVE);
    if(++current_size > (int)array.size() / 2) rehash();
    return true;
  }

  bool remove(const HashedObj & x)
  {
    int current_pos = find_pos(x);
    if(!is_active(current_pos)) return false;
    array[current_pos].info = DELETED;
    return true;
  }

  const HashedObj & at(const HashedObj & x) const
  // Precondition: none
  // Postcondition: Return value is x if found, else throws NotFoundException
  {
    int temp = find_pos(x);
    if(contains(x))//array[temp].element == x && array[temp].info == ACTIVE)
    {
       return array[temp].element;
     }
    else
    {
      throw NotFoundException();
    }
  }

  bool is_empty() const
  // Precondition: none
  // Postcondition: Return value is true if empty
  {
    if(current_size == 0) return true;
    return false;
  }

  enum EntryType{ACTIVE, EMPTY, DELETED};
  
  void print(std::ostream & out) const
  {
    for (unsigned i = 0; i < array.size() ; i++)
    {
      out << "\n" << i << ": ";
      if(array[i].info == ACTIVE)
       out << array[i].element.get_key();
    }
    out << "\n";
  }

private:
  struct HashEntry
  {
    HashedObj element;
    EntryType info;

    HashEntry(const HashedObj & e = HashedObj(), EntryType i = EMPTY)
      : element(e), info(i) {}

    const HashedObj & get_element() const {return element;}
  };

  std::vector<HashEntry> array;
  int current_size;

  bool is_active(int currentPos) const
  {return array[currentPos].info == ACTIVE;}

  int find_pos(const HashedObj & x) const
  {
    int offset = 1;
    int current_pos = myhash(x);
    while(array[current_pos].info != EMPTY && array[current_pos].element != x)
    {
      current_pos += offset;
      offset += 2;
      if(current_pos >= (int)array.size()) current_pos -= (int)array.size();
    }
    return current_pos;
  }

  void rehash()
  {
    std::vector<HashEntry> old_array = array;
    array.resize(next_prime(2 * (int)old_array.size()));
    for(int j = 0; j < (int)array.size(); ++j) array[j].info = EMPTY;
    current_size = 0;
    for(int i = 0; i < (int)old_array.size(); ++i)
      if(old_array[i].info == ACTIVE) insert(old_array[i].element);
  }

  int myhash(const HashedObj & x) const
  {
    int hash_val = hash(x);
    hash_val %= (int)array.size();
    if(hash_val < 0) hash_val += (int)array.size();
    return hash_val;
  }
};

int hash(const std::string & key);
int hash(int key);

#endif
