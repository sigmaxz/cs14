#include <iostream>

using namespace std;

template<class N>
struct ListNode
{
  N value;
  ListNode* leftChild;
  ListNode* rightChild;
  ListNode(N data,ListNode* left = NULL, ListNode* right=NULL)
  :value(data),leftChild(left), rightChild(right) {}
  
  
  N print(ListNode* t,N n = 0)
  {
    if(n == 0) cout << t->value << endl;
    else cout << n << ":" << t->value << endl;
    if(!t->leftChild && ! t->rightChild) return 0;
    if(t->leftChild)  print(t->leftChild,n +1);
    if(t->rightChild) print(t->rightChild, n+1);
    return 0;
  }
  void addNode(N v)
  {
    if(v == value) return;
    ListNode* l = leftChild;
    ListNode* r = rightChild;
    ListNode* c = NULL;
    if( v > value) 
    {
      if( r == NULL)
      {
        ListNode* temp = new ListNode<N>(v);
        rightChild = temp;
        return;
      }
      while(r->value < v)
      {
        r = r->rightChild;
        l = r->leftChild;
        c = l;
      }
      
  }
}
};

int main()
{
  ListNode<int> a(5);
  ListNode<int> b(4);
  ListNode<int> c(6);
  ListNode<int> d(2);
  a.leftChild = &b;
  a.rightChild = &c;
  b.leftChild = &d;
  a.print(&a);
  return 0;

}
