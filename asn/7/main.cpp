#include <cstdlib>      // provides: rand, RAND_MAX
#include <iostream>     // provides: cout
#include <algorithm>    // provides: swap

#include "Timer.h"
#include "Heapsort.h"
#include "Mergesort.h"
#include "Quicksort.h"

using namespace std;

void permute(vector<size_t> & a)
{
  for(size_t i = 0; i != a.size() - 1; ++i)
  {
    size_t p = rand() / (RAND_MAX / (a.size() - i) + 1);
    swap(a[i], a[i + p]);
  }
}

int main()//int argc, char ** argv)
{
  vector<int> a;
  a.push_back(7);
  a.push_back(3);
  a.push_back(5);
  a.push_back(8);
  a.push_back(2);
  a.push_back(9);
  a.push_back(6);
  a.push_back(1);
  a.push_back(4);
  a.push_back(0);

  cerr << "random permutation:";
  for(int i = 0; i != (int)a.size(); ++i) cerr << " " << a[i];
  cerr << endl;

  heapsort(a);
  //mergesort(a);
  //quicksort(a);

  cerr << "in ascending order:";
  for(int i = 0; i != (int)a.size(); ++i) cerr << " " << a[i];
  cerr << endl;

  Timer timer;
  size_t size = 300000;
  vector<size_t> b(size);
  for(size_t i = 0; i < size; ++i) b[i] = i;
  permute(b);

  timer.start();
  heapsort(b);
  //mergesort(b);
  //quicksort(b);
  timer.stop();

  cerr << timer.elapsedTime() << endl;

  return 0;
}
