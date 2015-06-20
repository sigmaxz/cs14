#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

#define VERTEX_NOT_FOUND 0;
//////////////////////////////////////////////////////////////////////////////////
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
      T pivotval = array[pivot];
      
      swap(array[pivot],array[right]);
      
      int store = left;
      
      for(int i = left; i < right; i++)
         if(array[i] > pivotval)
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
//--------------------------------------------------------------------------------
};
//////////////////////////////////////////////////////////////////////////////////
class Vertex
{
public:
   string name;
   int    degree;
   int    color;
//--------------------------------------------------------------------------------
   Vertex()
   {
      this->name   = "";
      this->degree = 0;
   }
//--------------------------------------------------------------------------------
   Vertex(string name, int degree)
   {
      this->name   = name;
      this->degree = degree;
   }
//--------------------------------------------------------------------------------
   void set(string name, int degree)
   {
      this->name   = name;
      this->degree = degree;
   }
//--------------------------------------------------------------------------------
   bool operator< (const Vertex& that){return degree < that.degree;}
//--------------------------------------------------------------------------------
   bool operator> (const Vertex& that){return degree > that.degree;}
//--------------------------------------------------------------------------------
};
//////////////////////////////////////////////////////////////////////////////////
class Graph
{
public:
   string* vertices;
   bool* visited;
   int** adjacency;
   int size;
   int cur;
//--------------------------------------------------------------------------------
   Graph(int size)
   {
      this->size = size;
      cur        = 0;
   
      vertices  = new string[size];
      visited   = new bool[size];
      adjacency = new int*[size];
      
      for(int i = 0; i < size; i++)
      {
         visited[i] = false;
         adjacency[i] = new int[size];
		 for( int j = 0; j < size; j++ )
			 adjacency[i][j] = 0;
      }
   }
//--------------------------------------------------------------------------------
   int indexof(string v)
   {  
      for(int i = 0; i < size; i++)
         if(vertices[i].compare(v) == 0)
            return i;
            
      return -1; 
   }
//--------------------------------------------------------------------------------
   void addvertex(string name)
   {
      vertices[cur++] = name;
   }
//--------------------------------------------------------------------------------
   void addedge(string v1, string v2)
   {
      int index1 = indexof(v1);
      int index2 = indexof(v2);
      
      if(index1 < 0 || index2 < 0)
      {
         throw VERTEX_NOT_FOUND;
      }
      
      adjacency[index1][index2] = 1;
      adjacency[index2][index1] = 1;
   }
//--------------------------------------------------------------------------------
   void removeedge(string v1, string v2)
   {
      int index1 = indexof(v1);
      int index2 = indexof(v2);
      
      if(index1 < 0 || index2 < 0)
      {
         throw VERTEX_NOT_FOUND;
      }
      
      adjacency[index1][index2] = 0;
      adjacency[index2][index1] = 0;
   }
//--------------------------------------------------------------------------------
   void print()
   {
      cout << "  ";
      for(int i = 0; i < size; i++)
         cout << vertices[i] << " ";
      cout << endl;

      for(int i = 0; i < size; i++)
      {
         cout << vertices[i] << " ";
         for(int j = 0; j < size; j++)
            cout << adjacency[i][j] << " ";
         cout << endl;
      }
   }
//--------------------------------------------------------------------------------
   void print_degrees()
   {
     Vertex list[size];

     for (int i = 0; i < size; i++)
     {
       int degree = 0;
       for (int j = 0; j < size ; j++)
       {
         if( adjacency[i][j] == 1)
          degree++;
       }
       list[i] = Vertex(vertices[i],degree);
    }

      QuickSorter<Vertex> sort;
      sort.quicksort(list,0,size-1);
      
      for (int k = 0; k < size ; k++)
      {
        cout << "(" << list[k].name << "," << list[k].degree << ") ";
        
      }
      cout << endl;
    }
   
//--------------------------------------------------------------------------------
   bool path_exists(string source, string destination)
   {
		
   }
//--------------------------------------------------------------------------------
};
//////////////////////////////////////////////////////////////////////////////////
Graph* makegraph()
{
   Graph* g = new Graph(11);
   
   g->addvertex("A");   g->addvertex("B");   g->addvertex("C");
   g->addvertex("D");   g->addvertex("E");   g->addvertex("F");
   g->addvertex("G");   g->addvertex("H");   g->addvertex("I");
   
   g->addvertex("J");
   g->addvertex("K");

   g->addedge("A","B"); g->addedge("D","G");

   g->addedge("A","F"); g->addedge("E","F");
   
   g->addedge("B","C"); g->addedge("E","H");
   g->addedge("B","E"); g->addedge("F","G");
   
   g->addedge("C","D"); g->addedge("H","I");
   g->addedge("C","F"); g->addedge("J","K");
   g->addedge("C","H");
   
   return g;
}
//////////////////////////////////////////////////////////////////////////////////
void ex03(Graph* g)
{  
   cout << "***********************Exercise 04*************************" << endl;
   cout << "****************What your output should look like**********" << endl;
   cout << "(C,4) (F,4) (B,3) (H,3) (E,3) (A,2) (G,2) (D,2) (K,1) (J,1) (I,1)" << endl;
   cout << endl;
   cout << "*************What your output actually looks like**********" << endl;   
   g->print_degrees();
   cout << "***********************************************************" << endl;
   cout << endl;
}
//////////////////////////////////////////////////////////////////////////////////
void ex04(Graph* g)
{

   bool test1 = g->path_exists("A","H");
   bool test2 = g->path_exists("A","K");
   
   cout << "***********************Exercise 05*************************" << endl;
   cout << "Existing path:     " << ((test1)  ? "SUCCEEDS" : "FAILS")  << endl;
   cout << "Non-existing path: " << ((!test2) ? "SUCCEEDS" : "FAILS")  << endl;
   cout << "***********************************************************" << endl;
   cout << endl;
   
}
//////////////////////////////////////////////////////////////////////////////////

int main()
{
   int choice = -1;
   
   Graph* g = makegraph();

   cout << "\nGraph:\n";
   g->print();
   cout << endl;
   
    while(choice != 0)
    {
       cout << "Enter exercise number (0 to quit): ";
       cin >> choice;

       
       switch(choice)
       {
          case 3: ex03(g); break;
          case 4: ex04(g); break;
       }
    }

   return 0;
}
