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
// INVARIANT for the AvlTree class:
//   1. For each node in the binary search tree,
//      the node's key is greater than its left subtree's nodes's keys
//      and less than its right subtree's nodes's keys.
//   2. When a node has no left child, node->left = NULL, and
//      when a node has no right child, node->right = NULL.
//   3. Data member root points to the root node of the binary search tree.
//      (At construction, root = NULL)
//   4. Each subtree is balanced before and after any operation with
//      a maximum 1 difference of height between its left and right subtrees
//   5. Each node maintains a count of occurrence of its element
//   6. Each node maintains its height in the tree

#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <string>
#include <iostream>

class AvlTree
{
  friend struct test_tree_t;
  friend struct test_1;
  friend struct test_2_3;
  friend struct test_4;
  friend struct test_5_6;
  friend struct test_7_8;
  friend struct test_9;
  friend struct test_10_15;
  friend struct test_16_20;
  
public:

  AvlTree();
  // Precondition: none
  // Postcondition: root = NULL
  AvlTree(const AvlTree & rhs);
  // Precondition: none
  // Postcondition: root points to new tree that is a copy of the tree
  // pointed to by rhs.root
  ~AvlTree();
  // Precondition: none
  // Postcondition: All nodes of the tree are reclaimed
  const AvlTree & operator =(const AvlTree & rhs);
  // Precondition: none
  // Postcondition: root points to new tree that is a copy of the tree
  // pointed to by rhs.root

  bool contains(const std::string & x) const;
  // Precondition: none
  // Postcondition: Return value is true if x is in tree
  void printTree(std::ostream & out = std::cout) const;
  // Precondition: out has been initialized
  // Postcondition: All nodes are printed in increasing order,
  // one item per line
  void insert(const std::string & x);
  // Precondition: none
  // Postcondition: If x in tree, node's count is incremented, else new
  // node added with x as the element and count = 1 and computed height and
  // heights updated along the path back to root and rotations if necessary
  void remove(const std::string & x);
  // Precondition: none
  // Postcondition: If x in tree and count > 1, node's count is decremented,
  // if x in tree and count == 1, node is deleted and heights updated along
  // the path back to the root and rotations performed if necessary

private:

  struct AvlNode
  {
    std::string element;
    AvlNode * left;
    AvlNode * right;
    int height;
    int count;

    AvlNode(const std::string & theElement, AvlNode * lt, AvlNode * rt,
      int h = 0, int c = 1)
      : element(theElement), left(lt), right(rt), height(h), count(c) {}
  };

  AvlNode * root;

  AvlNode * construct(const AvlNode * t);
  void destroy(AvlNode * t);
  bool contains(const std::string & x, AvlNode * t) const;
  void printTree(AvlNode * t, std::ostream & out) const;
  void insert(const std::string & x, AvlNode * & t);
  void remove(const std::string & x, AvlNode * & t);
  void rotateWithLeftChild(AvlNode * & k2);   // Figure 4.34
  void doubleWithLeftChild(AvlNode * & k3);   // Figure 4.38
  void rotateWithRightChild(AvlNode * & k1);  // Figure 4.36
  void doubleWithRightChild(AvlNode * & k1);  // Figure 4.39
  int height(AvlNode * t) const {return t == NULL ? -1 : t->height;}
};

inline bool less_than(const std::string & lhs, const std::string & rhs)
{
  if( lhs < rhs ) return true;
  return false;
}

#endif
