// FILE: Node.h
// PROVIDES: A class for a node in a linked list.
// Adapted from Data Structures & Other Objects using C++, third edition
// Michael Main and Walter Savitch

#ifndef NODE_H
#define NODE_H

#include <cstdlib>        // Provides size_t and NULL

class Node
{
public:

  // TYPEDEF
  typedef int value_type;

  // CONSTRUCTOR
  Node(const value_type& init_data = value_type(), Node* init_link = NULL)
  {data_field = init_data; link_field = init_link;}

  // Member functions to set the data and link fields:
  void set_data(const value_type& new_data) {data_field = new_data;}
  void set_link(Node* new_link) {link_field = new_link;}

  // Constant member function to retrieve the current data:
  value_type data() const {return data_field;}

  // Two slightly different member functions to retreive
  // the current link:
  const Node* link() const {return link_field;}
        Node* link()       {return link_field;}

private:
  value_type data_field;
  Node* link_field;
};

size_t list_length(const Node* head_ptr)
// Library facilities used: cstdlib
{
  const Node *cursor;
  size_t answer;

  answer = 0;
  for(cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    ++answer;

  return answer;
}

#endif
