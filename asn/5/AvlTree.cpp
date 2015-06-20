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
// Assignment: assignment 5
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================================

#include <iostream>
#include "AvlTree.h"
#include <algorithm>

using namespace std;

AvlTree::AvlTree()
:root(NULL) 
{}


AvlTree::AvlTree(const AvlTree & rhs)
{
  root = NULL;
  *this = rhs;
}

AvlTree::~AvlTree()
{
  destroy(root);
}
  // Precondition: none
  // Postcondition: All nodes of the tree are reclaimed
const AvlTree & AvlTree::operator =(const AvlTree & rhs)
{
  if(this != &rhs)
  {
    destroy(root);
    root = construct(rhs.root);
  }
  return *this;
}
  // Precondition: none
  // Postcondition: root points to new tree that is a copy of the tree
  // pointed to by rhs.root

bool AvlTree::contains(const std::string & x) const
{
  return contains(x,root);
}
  // Precondition: none
  // Postcondition: Return value is true if x is in tree
  
void AvlTree::printTree(std::ostream & out ) const
{
  if( root ==NULL) out << "Empty tree" << endl;
  else printTree(root,out);
}
  // Precondition: out has been initialized
  // Postcondition: All nodes are printed in increasing order,
  // one item per line
  
void AvlTree::insert(const std::string & x)
{
  insert(x,root);
}
  // Precondition: none
  // Postcondition: If x in tree, node's count is incremented, else new
  // node added with x as the element and count = 1 and computed height and
  // heights updated along the path back to root and rotations if necessary
void AvlTree::remove(const std::string & x)
{
  remove(x,root);
}

AvlTree::AvlNode * AvlTree::construct(const AvlNode * t)
{
  if(t == NULL) return NULL;
  return new AvlNode(t->element,construct(t->left), construct(t->right),t->height , t->count);
}

void AvlTree::destroy(AvlNode * t)
{
  if(t != NULL)
  {
    this->destroy(t->left);
    this->destroy(t->right);
    delete t;
  }
  t= NULL;
}

bool AvlTree::contains(const std::string & x, AvlNode * t) const
{
  if( t == NULL) return false;
  else if ( x < t->element) return contains(x,t->left);
  else if (t->element < x) return contains(x,t->right);
  else return true; 
}

void AvlTree::printTree(AvlNode * t, std::ostream & out) const
{
  if(t != NULL)
  {
    printTree(t->right,out);
    for (int i = 0; i < t->count; i++)
    {
      out << t->element << endl ;
    }
    
    printTree(t->left,out);
  }
}

void AvlTree::insert(const std::string & x, AvlNode * & t)
{
  if(t == NULL)
  { 
    t = new AvlNode(x,NULL,NULL,0,1);
  }
  else if ( x < t->element)
  {
    insert(x,t->left);
    if( height(t->left) - height(t->right) == 2)
    {
      if(x < t->left->element) rotateWithLeftChild(t);
    
      else
      { 
        doubleWithLeftChild(t);
      }
    }
  }
  else if (t->element < x)
  {
    insert(x,t->right);
    if(height (t->right) - height(t->left) == 2)
    {
      if(t->right->element < x) rotateWithRightChild(t);
      else 
      {
        doubleWithRightChild(t);
      }
    }
  }
  else
  { 
    t->count= t->count + 1;
  }
  t->height = max(height(t->left), height(t->right)) + 1;
}


void AvlTree::remove(const std::string & x, AvlNode * & t)
{
 if(t == NULL) return;
 if(x == t->element)
 {
   if(t->count > 1)
   { 
     t->count = t->count -1;
     return;
   }
   exit(1);
   AvlNode* temp = t;
   if(!t->left && !t->right)
   {
     t = (t->left != NULL) ? t->left: t->right;
     delete temp;
   }
 }
  if ( x < t->element)
  {
    remove(x,t->left);
    if(height(t->left) - height(t->right) == 2)
    {
      if(x < t->left->element) rotateWithLeftChild(t);
    }
    else doubleWithLeftChild(t);
  }
  else if (t->element < x)
  {
    remove(x,t->right);
    if(height (t->right) - height(t->left) == 2)
    {
      if(t->right->element <x) rotateWithRightChild(t);
      else doubleWithRightChild(t);
    }
  }
  else 
  {
    if ( x != t->element) return;
    
  }  
  t->height = max(height(t->left), height(t->right)) + 1;
  
}


void AvlTree::rotateWithLeftChild(AvlNode * & k2)   // Figure 4.34
{
  AvlNode *k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;
  k2->height = max(height(k2->left), height(k2->right)) +1;
  k1 ->height = max(height(k1->left),k2->height)+1;
  k2 = k1;
}
void AvlTree::doubleWithLeftChild(AvlNode * & k3)   // Figure 4.38
{
  rotateWithRightChild(k3->left);
  rotateWithLeftChild(k3);
}

void AvlTree::rotateWithRightChild(AvlNode * & k1)  // Figure 4.36
{
  AvlNode *k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;
  k1->height = max(height(k1->right),height(k1->left))+1;
  k2->height = max(height(k2->right),k1->height)+1;
  k1=k2;
}
void AvlTree::doubleWithRightChild(AvlNode * & k1)  
{
  rotateWithLeftChild(k1->right);
  rotateWithRightChild(k1);
  
}

