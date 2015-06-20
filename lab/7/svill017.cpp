#include <iostream>
#include <cmath>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////
/*problem 3
 * all of them go n times***
 * sorted is O(n^2) : the point to pivot tends to not cut properly in half since it sticks to the front
 * reverse is O(n^2) : the point to pivot tends to not cut properly in half since it sticks to the back
 * unsorted (nlg(n)) : due to random the point to pivot is somewhere in the middle cutting it in half 
 * a number of n 
 * 
 * /////////////
 * problem 4
 * bubble:9
 * quick:45
 * 
 */
template<class T> class QuickSorter
{
public:
//--------------------------------------------------------------------------------
   void swap(T& a, T& b)
   {
      T c   = a;
      a     = b;
      b     = c;
   }
//--------------------------------------------------------------------------------
   int partition(T* array, int left, int right, int pivot)
   {
      int pivotval = array[pivot];
      swap(array[pivot],array[right]);
      
      int store = left;
      
      for(int i = left; i < right; i++)
         if(array[i] < pivotval)
         {
            swap(array[i],array[store]);
            store++;
         }
      swap(array[store],array[right]);
      
      return store;
   }
//--------------------------------------------------------------------------------
   void quicksort(T* array, int left, int right)
   {
      if(right > left)
      {
         int newpivot = partition(array,left,right,left);
         quicksort(array,left,newpivot-1);
         quicksort(array,newpivot+1,right);
      }
   }
};

//////////////////////////////////////////////////////////////////////////////////
// THis function checks if there are 2 numbers in the array that sum to the
// parameter k. If they exist, return their indices respectively in index1
// and index2. len is the length of the array
//////////////////////////////////////////////////////////////////////////////////
bool sumequal(int* array, int k, const int& len, int& index1, int& index2)
{
  QuickSorter<int> a;
  a.quicksort(array,0,len-1);
  int left = 0;
  int right = len-1;
  
  while(right != left)
  {
    if(array[right]+array[left] == k)
    {
      index1 = left;
      index2 = right;
      return true;
    }
    if(array[right] + array[left] > k)
    {
      right--;
    }
    if( array[right]+array[left] < k)
    {
      left++;
    }
    if(right == left) return false;
  }
  
  
}
//////////////////////////////////////////////////////////////////////////////////
// This function gets an array of strings containing trues, falses, and maybes
// then reconstruct them so that falses are followed by maybes, and by trues
// len is the length of an array
//////////////////////////////////////////////////////////////////////////////////
void reconstruct(string* array, int len)
{
  unsigned min = 0;
  for (unsigned i = 0; i < len; i++)
  {
    if(array[i] == "false" )
    {
      string st = array[i];
      array[i] = array[min];
      array[min] = st;
      min++;
    }
      
    
  }
  for (unsigned j = 0; j < len; j++)
  {
    if(array[j] == "maybe")
    {
      string st = array[j];
      array[j] = array[min];
      array[min] = st;
      min++;
    }
     cerr << array[j] << endl; 
  }
    
}
  

//////////////////////////////////////////////////////////////////////////////////
void ex01()
{
   string array[12] = {"true","false","maybe","false","true","maybe","maybe",
                       "false","true","maybe","maybe","true"};
                       
   string answer[12] = {"false","false","false","maybe","maybe","maybe","maybe",
                        "maybe","true","true","true","true"};
                       
   
                    
   reconstruct(array,12);
   
   bool succeed = true;
   
   for(int i = 0; i < 12; i++)
      if(array[i].compare(answer[i]) != 0)
      {
         succeed = false;
         break;
      }
      
   cout << "*************************************************\n";
   cout << "Exercise 01: " << 
           ((succeed) ? "SUCCEEDED" : "FAILED") << endl;
   cout << "*************************************************\n";
}
//////////////////////////////////////////////////////////////////////////////////
void ex02()
{
   int array[9] = {9,11,13,4,6,28,-10,8,3};

   int index1;
   int index2;
   
   int key = 1;
   
   bool result = sumequal(array,key,9,index1,index2);
   
   if(!result || (array[index1] + array[index2] != key))
      result = false;
   else
      result = true;
      
   cout << "*************************************************\n";
   cout << "Exercise 02 test1: " << 
           ((result) ? "SUCCEEDED" : "FAILED") << endl <<
           "\tFirst number:  " << array[index1] << endl <<
           "\tSecond number: " << array[index2] << endl;
   
   
   key = 8;
   result = sumequal(array,key,9,index1,index2);
   cout << "Exercise 02 test2: " << 
           ((!result) ? "SUCCEEDED" : "FAILED") << endl;
   cout << "*************************************************\n";
   
}


int main()
{
   int choice = -1;
   
    while(choice != 0)
    {
		cout << "Enter exercise number (0 to exit): ";
		cin >> choice;

       
	    switch(choice)
		{
			case 1: ex01(); break;
			case 2: ex02(); break;
		}
    }

   return 0;
}
