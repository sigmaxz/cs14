#include <iostream>

using namespace std;

struct TreeNode 
{ 
 // I didn’t put this typedef here for show, use it where appropriate 
 typedef int ValueType; 
 
 ValueType value; 
 TreeNode * leftChild, * rightChild; 
 
 TreeNode(ValueType zvalue = ValueType(), TreeNode * zleftChild = NULL, 
 TreeNode * zrightChild = NULL) 
 : value(zvalue), leftChild(zleftChild), rightChild(zrightChild) 
{ } 
  ValueType print(TreeNode* t,ValueType n = 0)
  {
    if(n == 0) cout << t->value << endl;
    else cout << n << ":" << t->value << endl;
    if(!t->leftChild && ! t->rightChild) return 0;
    if(t->leftChild)  print(t->leftChild,n +1);
    if(t->rightChild) print(t->rightChild, n+1);
    return 0;
  }
  void addNode(ValueType v)
  {
    if(v == value) return;
    TreeNode* l = leftChild;
    TreeNode* r = rightChild;
    TreeNode* c = NULL;
    if( v > value) 
    {
      if( r == NULL)
      {
        TreeNode* temp = new TreeNode(v);
        rightChild = temp;
        return;
      }
      while(r->value < v)
      {
        r = r->rightChild;
        l = r->leftChild
        c = l;
      }
      
  }
    
};

int main()
{
  TreeNode a(5);
  TreeNode b(4);
  TreeNode c(6);
  TreeNode d(2);
  a.leftChild = &b;
  a.rightChild = &c;
  b.leftChild = &d;
  a.print(&a);
  return 0;
}

