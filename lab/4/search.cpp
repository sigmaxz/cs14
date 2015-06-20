// Course: CS 14 Spring 2012
//
// First Name: Samuel
// Last Name: Villarreal
// UCR Username: svill017
// UCR Email Address: svill017@student.ucr.edu
//
// Lecture Section: 001
// Lab Section: 022
// TA: Krystof Litomisk
//
// Assignment: assignment 2
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================================
#include <iostream> 
#include <vector>

using namespace std;

bool search(const vector<int> & v ,int value, size_t start , size_t end)
{
  size_t mid = (start + end) /2 ;
  if( v.size() <= 1 || end == 0) return value == v[0] ? true:false;
  else if (v[mid] == value) return true;
  else
  {
    if(value > v[mid])
    {
      if(mid == (mid + end)/2 ) return false;
       return search(v, value, mid, end);
     }
     else
     {
       if( mid == (start+mid)/2) return false;
       return search(v,value, start, mid);
     }
       
  }
  return false;
}

struct lNode
{
  lNode* next;
};

bool cycle( lNode* h)
{
  lNode* cur = h;
  lNode* fcur = h;
  while(cur -> next)
  {
    cur =cur-> next;
    if(!(fcur -> next ->next)) return false;
    fcur = fcur->next->next;
    if(cur == fcur) return true;
  }
  
  return false;
}

int main()
{
  vector<int> a;
  a.push_back(2);
  a.push_back(5);
  a.push_back(7);
  a.push_back(10);
  a.push_back(12);
  cout << "2,5,7,19,12 (1to search 0 to escape)";
  int choice;
  cin >> choice;
  while( choice == 1)
  {
    cout << " num?:";
    cin >> choice;
    if ( search(a,choice,0,a.size()) )
    {
      cout << "found " << endl;
    }
    else cout << "missing" << endl;
    cout << "again?:(0/1)";
    cin >> choice;
  }
  lNode h;
  lNode b;
  lNode c;
  lNode d;
  
  h.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &b;
  
  lNode* q = &h;
  if( cycle(q) )
  {
    cout << "there is a cycle" << endl;
  }
  else cout << "no cycle " << endl;
  
  return 0;
}
