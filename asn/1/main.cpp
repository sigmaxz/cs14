#include "MyString.h"
#include <iostream>

using namespace std;
  
int main()
{
  MyString a;
  MyString b("b");
  MyString c(b);
  MyString d("Average");
  MyString e = "hello";
  
  cout << e << " length: " << e.length() << endl;
  cout << "index of e(should be 1): " << e.indexOf('e') << endl;
  cout << "index of h(should be 0): " << e.indexOf('h') << endl;
  cout << "index of o(should be 4): " << e.indexOf('o') << endl;
  /* error was recognized
   */
  //cout << "index of x(error): " << e.indexOf('x') << endl;
  cout << d << " length: " << d.length() << endl;
  cout << "index check for Average(positions 0,1,6 answers : A v e ::";
  cout << d[0] << d[1] << d[6] << endl;
  // error has been checked and thrown when out of bounds
  a = c;
  cout << "this is a:" << a << endl;
  if(a == c )
  {
    cout << "good" << endl;
  }
  else
  {
     cout<< "bad" << endl;
     
  }
  d += e;
  //cout << "here:" << d << endl;
  //MyString q= e.reverse();
  cout << "d:" << d << endl;
  cout << b << b.length();
  cout << " " << b << endl;
  cout << "reading enter :";
  cin >> a;
  cout <<"a:" <<  a << endl;
  cout << endl << c << " " << c.getMemoryAllocation();
  
  return 0;
}
