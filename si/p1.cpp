#include <iostream>
#include <istream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
  vector<int> nums;
  string snum;
  int num;
  cout << "?:" ;
  getline(cin, snum);
  stringstream ui(snum);
  while(ui >> num)
  {
    nums.push_back(num);
  }
  
  for (size_t i = 0; i < nums.size() ; i++)
  {
    cout << nums[i] * 2 << " ";
  }
  
  
    
    
  return 0;
}
