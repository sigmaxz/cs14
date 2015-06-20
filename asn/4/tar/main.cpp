#include <iostream>
#include <fstream>
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "Stack.h"
#include "Queue.h"
#include "ContainerUnderflow.h"

using namespace std;

int main(int argc, char ** argv)
{
  if(argc != 2)
  {cerr << "usage: " << argv[0] << " test_number" << endl; exit(1);}

  ofstream out("result.txt");

  int test = atoi(argv[1]);

  if(test == 1)
  {
    if(is_balanced("()")) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 2)
  {
    if(is_balanced("(()")) out << 0 << endl;
    else out << test << endl;
  }

  if(test == 3)
  {
    if(is_balanced("())")) out << 0 << endl;
    else out << test << endl;
  }

  if(test == 4)
  {
    if(is_balanced("(())")) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 5)
  {
    Stack * stack;
    stack = new ArrayStack;
    if(stack->is_empty()) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 6)
  {
    Stack * stack;
    stack = new LinkedStack;
    if(stack->is_empty()) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 7)
  {
    Queue * queue;
    queue = new ArrayQueue;
    if(queue->is_empty()) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 8)
  {
    Queue * queue;
    queue = new LinkedQueue;
    if(queue->is_empty()) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 9)
  {
    Stack * stack;
    stack = new ArrayStack;
    stack->push("hello");
    if(!stack->is_empty()) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 10)
  {
    Stack * stack;
    stack = new LinkedStack;
    stack->push("hello");
    if(!stack->is_empty()) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 11)
  {
    Queue * queue;
    queue = new ArrayQueue;
    queue->enq("hello");
    if(!queue->is_empty()) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 12)
  {
    Queue * queue;
    queue = new LinkedQueue;
    queue->enq("hello");
    if(!queue->is_empty()) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 13)
  {
    Stack * stack;
    stack = new ArrayStack;
    stack->push("hello");
    if(!stack->is_full()) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 14)
  {
    Stack * stack;
    stack = new LinkedStack;
    stack->push("hello");
    if(!stack->is_full()) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 15)
  {
    Queue * queue;
    queue = new ArrayQueue;
    queue->enq("hello");
    if(!queue->is_full()) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 16)
  {
    Queue * queue;
    queue = new LinkedQueue;
    queue->enq("hello");
    if(!queue->is_full()) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 17)
  {
    Stack * stack;
    stack = new ArrayStack;
    try
    {
      stack->pop();
      out << 0 << endl;
      exit(0);
    }
    catch(ContainerUnderflow e)
    {
      if(e.what() == "Container Underflow") out << test << endl;
      else out << 0 << endl;
    }
  }

  if(test == 18)
  {
    Stack * stack;
    stack = new LinkedStack;
    try
    {
      stack->pop();
      out << 0 << endl;
      exit(0);
    }
    catch(ContainerUnderflow e)
    {
      if(e.what() == "Container Underflow") out << test << endl;
      else out << 0 << endl;
    }
  }

  if(test == 19)
  {
    Queue * queue;
    queue = new ArrayQueue;
    try
    {
      queue->deq();
      out << 0 << endl;
      exit(0);
    }
    catch(ContainerUnderflow e)
    {
      if(e.what() == "Container Underflow") out << test << endl;
      else out << 0 << endl;
    }
  }

  if(test == 20)
  {
    Queue * queue;
    queue = new LinkedQueue;
    try
    {
      queue->deq();
      out << 0 << endl;
      exit(0);
    }
    catch(ContainerUnderflow e)
    {
      if(e.what() == "Container Underflow") out << test << endl;
      else out << 0 << endl;
    }
  }

  if(test == 21)
  {
    Stack * stack;
    stack = new ArrayStack;
    Stack::fill_all(*stack, "random_short.txt");
    Stack::empty_all(*stack, "ArrayStackOutput.txt");
  }

  if(test == 22)
  {
    Stack * stack;
    stack = new LinkedStack;
    Stack::fill_all(*stack, "random_short.txt");
    Stack::empty_all(*stack, "LinkedStackOutput.txt");
  }

  if(test == 23)
  {
    Queue * queue;
    queue = new ArrayQueue;
    Queue::fill_all(*queue, "random_short.txt");
    Queue::empty_all(*queue, "ArrayQueueOutput.txt");
  }

  if(test == 24)
  {
    Queue * queue;
    queue = new LinkedQueue;
    Queue::fill_all(*queue, "random_short.txt");
    Queue::empty_all(*queue, "LinkedQueueOutput.txt");
  }

  return 0;
}
