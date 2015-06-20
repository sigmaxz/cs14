#include <iostream>
#include <vector>

using namespace std;

template<class P>
void printVector(vector<P> v)
{
  for (int i = 0; i < v.size() ; i++)
  {
    cout << v[i] << ",";
    
  }
}

int main()
{
  vector<int> a; 
  a.push_back(3);
  a.push_back(4); 
  printVector<int>(a);
  
  cout << endl << 1 << endl;
  
  vector<string> b;
  b.push_back("he");
  b.push_back("wo");
  printVector<string>(b);
  
  cout << endl << 2 << endl;
  vector<string> c;
  c.push_back("he");
  c.push_back("wo");
  printVector(c);
  return 0;
}
