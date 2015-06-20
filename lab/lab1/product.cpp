#include <iostream>

using namespace std;

void sequence(int num)
{
  if( num < 1)
  {
    cout << "sorry too small\n";
    return;
  }
  
    cout << 1 << " ";
    if(num < 2)
    {
      return;
    }
    cout << 2 << " ";
    int temp1 = 1;
    int temp2 = 2;
    int temp3 = 0;
    while(num >= temp1 * temp2)
    {
      cout << temp1* temp2 << " ";
      temp3 = temp2;
      temp2 = temp1 * temp2;
      temp1 = temp3;
    }
}

int main()
{
  int num;
  cout << "enter a number :";
  cin >> num;
  sequence(num);
  
  return 0;
  
}
