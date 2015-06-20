#include <iostream>
#include <map>

using namespace std;

int main()
{
  map<int,int> m;
  int first,second;
  cout << "enter stuffz :";
  do
  {
    cin >> first >> second;
    if(first != 0 && second != first)
    {
      m[first] = second;
    }
  } while( first != 0 && second!= 0);
  
  cout << "give me stuffz :";
  cin >> first;
  cout << m[first] ;

  
  return 0;
}
  
  
