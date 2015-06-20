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
// Assignment: lab5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================================
#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <stack>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////
class TreeNode
{
public:
   TreeNode* left;
   TreeNode* right;
   int item;
   //--------------------------------------------------------------------------
   TreeNode()
   {
      left    = NULL;
      right   = NULL;
      item    = 0;
   }
   //--------------------------------------------------------------------------
   TreeNode(TreeNode *left, TreeNode* right, int item)
   {
      this->left    = left;
      this->right   = right;
      this->item    = item;
   }
   //--------------------------------------------------------------------------
};
//////////////////////////////////////////////////////////////////////////////////
class BST
{
public:
   TreeNode* root;
   //--------------------------------------------------------------------------
   BST(){root = NULL;}
   //--------------------------------------------------------------------------
   BST(TreeNode* node){root = node;}
   //--------------------------------------------------------------------------
   BST(BST* left, BST *right, int item)
   {
      root = new TreeNode(left->root,right->root,item);
   }
   //--------------------------------------------------------------------------
   void preorder(TreeNode* start)
   {
      if(start == NULL) return;
      
      cout << start->item << " ";
      preorder(start->left);
      preorder(start->right);
   }
   //--------------------------------------------------------------------------
   void inorder(TreeNode* start)
   {
      if(start == NULL) return;
      
      inorder(start->left);
      cout << start->item << " ";
      inorder(start->right);
   }
   //--------------------------------------------------------------------------
   void postorder(TreeNode* start)
   {
      if(start == NULL) return;
      
      postorder(start->left);
      postorder(start->right);
      cout << start->item << " ";
   }
   //--------------------------------------------------------------------------
   //Return a pointer to where the searchkey, if it exists, is
   //--------------------------------------------------------------------------
   TreeNode* recursive_find(TreeNode* tnode, int i)
   {
      if(tnode == NULL)        return NULL;
      else if(tnode->item > i) return recursive_find(tnode->left,i);
      else if(tnode->item < i) return recursive_find(tnode->right,i);
      else                     return tnode;
   }
   //--------------------------------------------------------------------------
   TreeNode* find(int i) {return recursive_find(root,i);}
   //--------------------------------------------------------------------------
   TreeNode* get_max(TreeNode* node)
   {
      if(node != NULL)
         while(node->right != NULL)
            node = node->right;
            
       return node;
   }
   //--------------------------------------------------------------------------
   TreeNode* get_min(TreeNode* node)
   {
      if(node != NULL)
         while(node->left != NULL)
            node = node->left;
            
       return node;
   }
   //--------------------------------------------------------------------------
   void insert(int i)
   {
      recursive_insert(root,i);
   }
   //--------------------------------------------------------------------------
   void recursive_insert(TreeNode* &tnode, int i)
   {
      if(tnode == NULL)        tnode = new TreeNode(NULL,NULL,i);
      else if(tnode->item > i) recursive_insert(tnode->left,i);
      else if(tnode->item < i) recursive_insert(tnode->right,i);
      else                     return;
   }
   //--------------------------------------------------------------------------
   void remove(TreeNode* &node, int i)
   {
      if(node == NULL) 
         return;
         
      else if(node->item > i) 
         remove(node->left,i);
         
      else if(node->item < i) 
         remove(node->right,i);
         
      else if(node->left != NULL && node->right != NULL)
      {
         node->item = get_min(node->right)->item;
         remove(node->right,node->item);
      }
      else
      {
         TreeNode* oldnode = node;
         node = (node->left != NULL) ? node->left : node->right;
         delete oldnode;
      }
   }
   //--------------------------------------------------------------------------
   
   

   //--------------------------------------------------------------------------
   //This function counts the number of nodes of the subtree rooted
   //at node. It uses NO helper function
   //--------------------------------------------------------------------------
   int iCount(TreeNode* start)
   {
     if(!start) return 0;
     return 1 + iCount(start->left) + iCount(start->right);
   }
   //--------------------------------------------------------------------------
   //This function returns the maximum depth of the subtree rooted
   //at node. It uses NO helper function
   //--------------------------------------------------------------------------
   int depth(TreeNode* node)
   {
     if(!node) return -1;
     if(node->left == NULL && node->right == NULL) return 0;
     return depth(node->left) >= depth(node ->right) ? 1 + depth(node ->left) : 1 + depth(node->right);
     
   }
   //--------------------------------------------------------------------------
   //This function counts the number of leaves of the subtree rooted
   //at node. It uses NO helper function
   //--------------------------------------------------------------------------
   int leaves(TreeNode* node)
   {
     if(!node) return 0;
     if(node->left == NULL && node->right == NULL) return 1;
     return leaves(node->left) + leaves(node->right);
   }


};
//////////////////////////////////////////////////////////////////////////////////
BST* form_test_tree()
{
   BST* test = new BST();

   test->insert(6);
   test->insert(2);
   test->insert(8);
   test->insert(1);
   test->insert(5);
   test->insert(3);
   test->insert(4);
   test->insert(7);
   test->insert(9);
   test->insert(30);
   test->insert(15);
   test->insert(32);
   
   return test;
}
//////////////////////////////////////////////////////////////////////////////////
void ex01()
{
   double predicted = 12;
   
   BST* test1 = form_test_tree();
   BST* test2 = new BST();
   
   double size1 = test1->iCount(test1->root);
   double size2 = test2->iCount(test2->root);

   
   cout << "####################### Exercise 01 ##########################"
        << endl;
   
   if(predicted != size1)
      cout << "Testing size function in normal case FAILS" << endl
           << "Correct result: " << predicted << endl
           << "Actual result:  " << size1 << endl;
   else
      cout << "Testing size function in normal case SUCCEEDS" << endl;
      
      
   if(0 != size2)
      cout << "Testing size function in empty case FAILS" << endl
           << "Correct result: " << 0 << endl
           << "Actual result:  " << size2 << endl;
   else
      cout << "Testing size function in empty case SUCCEEDS" << endl;
}
//////////////////////////////////////////////////////////////////////////////////
void ex02()
{
   double predicted = 4;
   
   BST* test1 = form_test_tree();
   BST* test2 = new BST();
   
   double d1 = test1->depth(test1->root);
   double d2 = test2->depth(test2->root);
   
   cout << "####################### Exercise 02 ##########################"
        << endl;
           
   if(predicted != d1)
      cout << "Testing depth function in normal case FAILS" << endl
           << "Correct result: " << predicted << endl
           << "Actual result:  " << d1 << endl;
   else
      cout << "Testing depth function in normal case SUCCEEDS" << endl;
      
      
   if(-1 != d2)
      cout << "Testing depth function in empty case FAILS" << endl
           << "Correct result: " << -1 << endl
           << "Actual result:  " << d2 << endl;
   else
      cout << "Testing depth function in empty case SUCCEEDS" << endl;
}
//////////////////////////////////////////////////////////////////////////////////
void ex03()
{
   double predicted = 7;
   
   BST* test1 = form_test_tree();
   BST* test2 = new BST();
   
   test1->insert(12);
   test1->insert(16);
   test1->insert(60);
   test1->insert(31);
   
   double l1 = test1->leaves(test1->root);
   double l2 = test2->leaves(test2->root);
   
   cout << "####################### Exercise 03 ##########################"
        << endl;
   
   if(predicted != l1)
      cout << "Testing leaves function in normal case FAILS" << endl
           << "Correct result: " << predicted << endl
           << "Actual result:  " << l1 << endl;
   else
      cout << "Testing leaves function in normal case SUCCEEDS" << endl;
      
      
   if(0 != l2)
      cout << "Testing leaves function in empty case FAILS" << endl
           << "Correct result: " << 0 << endl
           << "Actual result:  " << l2 << endl;
   else
      cout << "Testing leaves function in empty case SUCCEEDS" << endl;
}
//////////////////////////////////////////////////////////////////////////////////
int main()
{
   ex01();
   ex02();
   ex03();
   
   
   return 0;
   
}
/////////////////////////////////////////////////////////////////////////////
// problem 4
/*the function my_func acts as a boolean function that returns true if the
*  children of a node are in a valid binary search tree layout meaning 
* left node value would be less than the parent value and the right node value 
* would be more.
*/
