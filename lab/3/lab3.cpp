#include <iostream>     // provides cout
#include <vector>       // provides vector
#include "Node.h"

// Helper functions //////////////////////////////////////////////////////////
Node* ordered_list(int min, int max);
void print_list(const Node* head_ptr);
//////////////////////////////////////////////////////////////////////////////

// Lab 3 fnuctions ///////////////////////////////////////////////////////////
//Implement the following. Their descriptions are in the lab 3 description pdf.
void split( Node* L, Node*& P, Node*& Q)
{
 P = L;
 for(int i = 0; i < list_length(L) /2.0 -1 ; i++)
 {
   P = P->link();
 }
 Q = P->link();
 P->set_link(NULL);
 P = L;
}

Node* relative_complement( Node* L1,  Node* L2)
{
  Node* L3 = NULL;
  Node* newhead = NULL;
  const Node* t1 = L1;
  const Node* t2 = L2;
  int sent = 0;
 while(t1 != NULL )
 {
   if(t1->data() < t2->data() || t2 == NULL)
   {
     if(sent == 0)
     {
       L3 = new Node(t1->data(), NULL);
       newhead = L3;
       sent++;
     }
     else
     {
       Node* temp = new Node(t1->data(),NULL);
       L3->set_link(temp);
       L3 = temp;
       
     }
     t1 = t1->link();
   }
   else if(t1->data() > t2->data())
   {
     t2 = t2->link();
   }
   else
   {
     t2 = t2->link();
     t1 = t1->link();
   }
 }
   return newhead;
}


Node* reverse_list(Node*& head_ptr)
{
 if(head_ptr->link() == NULL) return head_ptr;

 Node* next = head_ptr->link();
 Node* temp = reverse_list(next);
 head_ptr->link()->set_link(head_ptr);
 head_ptr->set_link(NULL);

 head_ptr = temp;
return head_ptr;
}

Node* nth_node(Node* head_ptr, int n)
{
  Node* temp= head_ptr;
  for (size_t i = 0; i < list_length(head_ptr) - n ; i++)
  {
    temp = temp->link();
  }
  return temp;
  
}
//////////////////////////////////////////////////////////////////////////////

using namespace std;

int main()
{
  // List 1
  cout << "List 1" << endl;
  Node* list_1 = ordered_list(0, 9);
  print_list(list_1);cout << endl;

  // List 2
  cout << "List 2" << endl;
  Node* list_2 = ordered_list(4, 13);
  print_list(list_2);cout << endl;

  // PROBLEM 1: Split
  cout << "PROBLEM 1:" << endl;
  Node* P;
  Node* Q;
  split(list_1, P, Q);
  cout << "List P" << endl;
  print_list(P);cout << endl;
  cout << "List Q" << endl;
  print_list(Q);cout << endl;

  //// PROBELM 2: Relative complement
  cout << "PROBLEM 2:" << endl;
  cout << "Relative complement of L2 in L1" << endl;
  Node* comp = relative_complement(list_1, list_2);
  print_list(comp);cout << endl;

  //// PROBLEM 3: Nth node
  cout << "PROBLEM 3:" << endl;
  Node* nth = nth_node(list_2, 5);
  cout << "The fifth node from the tail end of list 2 is " << nth->data() << endl;
  cout << endl;

  //// PROBLEM 4: Reverse
  cout << "PROBLEM 4:" << endl;
  cout << "List 2 (reversed)" << endl;
  reverse_list(list_2);
  print_list(list_2);cout << endl;

  return 0;
}

Node* ordered_list(int min, int max)
{
  Node* head_ptr = NULL;
  for(int i = max - min + 1; i > 0; i--)
  {
    Node* node = new Node(i + min - 1, head_ptr);
    head_ptr = node;
  }
  return head_ptr;
}

void print_list(const Node* head_ptr)
{
  while(head_ptr != NULL)
  {
    cout << head_ptr->data() << endl;
    head_ptr = head_ptr->link();
  }
}
