// THIS IS A POLYMORPHIC CLASS; THE METHODS ARE VIRTUAL,
// MEANING THAT WHEN A POINTER OF THIS CLASS TYPE POINTS TO
// A DERIVED CLASS, THE METHODS IT CALLS WILL BE THE METHODS DEFINED
// BY THE DERIVED CLASS TO WHICH THE POINTER IS CURRENTLY POINTING.
// VISTI http://www.cplusplus.com/doc/tutorial/polymorphism/ FOR MORE
// INFORMATION.

// virtual void push(const std::string & word)
//   Precondition: none
//   Postcondition: word is at the top of the stack
// virtual void pop()
//   Precondition: none
//   Postcondition: the element at the top of stack is removed
// virtual std::string top() const
//   Precondition: none
//   Postcondition: Return value is copy of element at the top of the stack
// virtual bool is_empty() const
//   Precondition: none
//   Postcondition: Return value is true if no elements in stack
// virtual bool is_full() const
//   Precondition: none
//   Postcondition: Return value is true if no more elements can be added

#ifndef STACK_H
#define STACK_H

#include <string>

class Stack
{
public:
  virtual ~Stack() {}
  virtual void push(const std::string &) = 0;
  virtual void pop() = 0;
  virtual std::string top() const = 0;
  virtual bool is_empty() const = 0;
  virtual bool is_full() const = 0;
  static void fill_all(Stack & stack, const std::string & file);
  static void empty_all(Stack & stack, const std::string & file);
};

bool is_balanced(const std::string & brackets);

#endif
