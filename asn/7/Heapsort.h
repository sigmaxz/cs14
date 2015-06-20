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
// Assignment: assignment 7
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================================
#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <vector>

using namespace std;

template< typename obj>
void heapsort(vector<obj> & v)
{
  for (int i = v.size()/2; i >= 0 ; i--)
  {
    perc_down(v,i, v.size());
  }
  for(int b = v.size()-1; b > 0; b--)
  {
    int temp = v[0];
    v[0] = v[b];
    v[b] = temp;
    perc_down(v,0,b);
  }
  
}

inline int left(int spot)
{
  return 2* spot +1;
}

template<typename obj>
void perc_down(vector<obj> & v,int a, int b)
{
  int child;
  obj temp;
  
  for( temp = v[a]; left(a) < b; a = child)
  {
    child = left(a);
    if(child != b -1 && v[child] < v[child+1])
    {
      child++;
    }
    if(temp < v[child]) v[a] = v[child];
    else break;
  }
  v[a] = temp;
}
  

#endif
