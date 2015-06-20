#include <iostream>
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"

using namespace std;

int main()
{
  ArrayQueue b;
  b.enq("hi");
  ArrayQueue a(b);
  string hold = a.front();
  //cout << hold << endl;
  a.deq();
  return 0;
}
