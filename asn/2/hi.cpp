#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
  MyString a;
  MyString b(a);
  ListNode* cursor = b.head;
  
    if( cursor == NULL)
    {
      cout << "its NULL";
    }
    
  return 0;
}
