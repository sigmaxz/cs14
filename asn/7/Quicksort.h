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
#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>

using namespace std;


template <typename obj>
void insertionsort(vector<obj> & a, int left, int right)
{
  int z;
  for(int p = left;p < right-left+1 ; p++)
  {
    obj tmp = a[p];
    for(z = p ; p > 0 && tmp < a[z-1]; z--)
    {
    a[z]=a[z-1];
    }
    a[z] = tmp;
  }
    
}

template <typename obj>
const obj & median(vector<obj> & v , int l , int r)
{
  int mid = (l+r)/2;
  obj temp;
  if(v[mid] < v[l])
  {
    temp = v[l];
    v[l] = v[mid];
    v[mid] = temp;
  }
  if( v[r] < v[l])
  {
    temp = v[l];
    v[l] = v[r];
    v[r] = temp;
  }
  if(v[r] < v[mid])
  {
    temp = v[r];
    v[r] = v[mid];
    v[mid] = temp;
  }
  
  temp = v[mid];
  v[mid] = v[r-1];
  v[r-1] = temp;
  return v[r-1];
}

template<typename obj>      
void quicksort(vector<obj> & v, int l, int r)
{
  if(l+10 <= r)
  {
    obj pivot = median(v,l,r);
    int i = l;
    int j = r-1;
    for (;;)
    {
      while(v[i++] < pivot){}
      while(pivot < v[j--]){}
      if(i < j)
      {
        obj temp = v[i];
        v[i] = v[j];
        v[j] = temp;
      }
      else break;
    }
    
    obj tmp = v[i];
    v[i] = v[r-1];
    v[r-1] = tmp;
    
    quicksort(v,l,i-1);
    quicksort(v,i+1,r);
  }
  else
  insertionsort(v,l,r);

}

template<typename obj>
void quicksort(vector<obj> & v)
{
  quicksort(v,0,v.size()-1);
}



#endif 
