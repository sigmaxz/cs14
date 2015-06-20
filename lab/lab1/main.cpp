#include <iostream>
#include <cmath>

using namespace std;

int num_int (int num)
{
  if( num == 0)
  {
    return 0;
  }
  else
  {
    if(num % 2 != 0)
    {
      return 1 + num_int(num / 10);
    }
    else
    {
      return num_int(num / 10);
    }
  }
}
  

int main()
{
  int num;
  cout << "enter a number :";
  cin >> num;
  int count = num_int(num);
  cout << count << endl;
  
  return 0;
  
}
