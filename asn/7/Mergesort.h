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
#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>

using namespace std;

template<typename obj>
void merge(vector<obj> & v, vector<obj> & t,int l, int mid, int r)
{
  int l_end = mid-1;
  int temp = l;
  int num_eles = r-l +1;
  
  while(mid <= r && l <= l_end)
  {
    if(v[l] <= v[mid]) t[temp++] = v[l++] ;
    else t[temp++] = v[mid++];
  }
  while( l <= l_end)
  {
    t[temp++] = v[l++];
  }
  while( mid <= r )
  {
    t[temp++] = v[mid++];
  }
  for (int i = 0; i < num_eles; i++,r--)
  {
    v[r] = t[r];
  }
  
}

template<typename obj>
void mergesort(vector<obj> & v, vector<obj> & t,int l, int r)
{
  if(l < r)
  {
    int mid = (l + r) / 2;
    mergesort(v,t,l,mid);
    mergesort(v,t,mid+1,r);
    merge(v,t,l,mid+1,r);
  }
}

template< typename obj>
void mergesort(vector<obj> & v)
{
  vector<obj> temp_a(v.size());
  mergesort(v,temp_a, 0,v.size()-1);
}



#endif
