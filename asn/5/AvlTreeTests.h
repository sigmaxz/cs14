#include <iostream>
#include <fstream>
#include "AvlTree.h"

using namespace std;

struct test_tree_t
{
  void operator()(AvlTree::AvlNode * & root)
  // Left tree in middle of page 143 of textbook (with string instead of int)
  {
    AvlTree::AvlNode * child = new AvlTree::AvlNode("ice", NULL, NULL);
    AvlTree::AvlNode * parent = new AvlTree::AvlNode("fire", NULL, child, 1);
    child = parent;
    parent = new AvlTree::AvlNode("element", NULL, child, 2);
    child = new AvlTree::AvlNode("duck", NULL, NULL);
    parent->left = child;
    child = parent;
    root = new AvlTree::AvlNode("cart", NULL, child, 3);
    child = new AvlTree::AvlNode("car", NULL, NULL);
    parent = new AvlTree::AvlNode("ball", NULL, child, 1);
    child = new AvlTree::AvlNode("air", NULL, NULL);
    parent->left = child;
    root->left = parent;
  }
} test_tree;

struct test_1
{
  bool operator()(int)
  {
    AvlTree tree;
    if(tree.root != NULL) return false;
    return true;
  }
} default_constructor_test;

struct test_2_3
{
  bool operator()(int test)
  {
    if(test == 2)
    {
      AvlTree tree;
      tree.root = NULL;
      AvlTree copy(tree);
      if(copy.root != NULL) return false;
    }
    else if(test == 3)
    {
      AvlTree tree;
      test_tree(tree.root);
      AvlTree copy(tree);
      if(copy.root->element != "cart") return false;
      if(copy.root->left->element != "ball") return false;
      if(copy.root->right->element != "element") return false;
      if(copy.root->left->left->element != "air") return false;
      if(copy.root->left->right->element != "car") return false;
      if(copy.root->right->left->element != "duck") return false;
      if(copy.root->right->right->element != "fire") return false;
      if(copy.root->right->right->right->element != "ice") return false;
    }
    else exit(1);
    return true;
  }
} copy_constructor_test;

struct test_4
{
  bool operator()(int)
  {
    {
      AvlTree tree;
      test_tree(tree.root);
    }
    return true;
  }
} destructor_test;

struct test_5_6
{
  bool operator()(int test)
  {
    if(test == 5)
    {
      AvlTree tree;
      tree.root = NULL;
      AvlTree copy;
      copy = tree;
      if(copy.root != NULL) return false;
    }
    else if(test == 6)
    {
      AvlTree tree;
      test_tree(tree.root);
      AvlTree copy;
      copy = tree;
      if(copy.root == tree.root) return false;
      if(copy.root->left == tree.root->left) return false;
      if(copy.root->right == tree.root->right) return false;
      if(copy.root->left->left == tree.root->left->left) return false;
      if(copy.root->left->right == tree.root->left->right) return false;
      if(copy.root->right->left == tree.root->right->left) return false;
      if(copy.root->right->right == tree.root->right->right) return false;
      if(copy.root->right->right->right == tree.root->right->right->right)
        return false;
      if(copy.root->element != "cart") return false;
      if(copy.root->left->element != "ball") return false;
      if(copy.root->right->element != "element") return false;
      if(copy.root->left->left->element != "air") return false;
      if(copy.root->left->right->element != "car") return false;
      if(copy.root->right->left->element != "duck") return false;
      if(copy.root->right->right->element != "fire") return false;
      if(copy.root->right->right->right->element != "ice") return false;
    }
    else exit(1);
    return true;
  }
} assignment_operator_test;

struct test_7_8
{
  bool operator()(int test)
  {
    if(test == 7)
    {
      AvlTree tree;
      test_tree(tree.root);
      if(tree.contains("sky")) return false;
    }
    else if(test == 8)
    {
      AvlTree tree;
      test_tree(tree.root);
      if(!tree.contains("car")) return false;
    }
    else exit(1);
    return true;
  }
} contains_test;

struct test_9
{
  bool operator()(int)
  {
    AvlTree tree;
    test_tree(tree.root);
    ofstream out("print.txt");
    tree.printTree(out);
    out.close();
    ifstream in("print.txt");
    string word;
    in >> word; if(word != "air") return false;
    in >> word; if(word != "ball") return false;
    in >> word; if(word != "car") return false;
    in >> word; if(word != "cart") return false;
    in >> word; if(word != "duck") return false;
    in >> word; if(word != "element") return false;
    in >> word; if(word != "fire") return false;
    in >> word; if(word != "ice") return false;
    in >> word; if(!in.eof()) return false;
    in.close();
    return true;
  }
} printTree_test;

struct test_10_15
{
  bool operator()(int test)
  {
    if(test == 10)
    {
      AvlTree tree;
      tree.root = NULL;
      tree.insert("baseball");
      if(tree.root->element != "baseball") return false;
      if(tree.root->height != 0)return false;
      if(tree.root->left != NULL) return false;
      if(tree.root->right != NULL) return false;
    }
    else if(test == 11)
    // insertions without rotations
    {
      AvlTree tree;
      tree.insert("cart");
      tree.insert("ball");
      tree.insert("element");
      tree.insert("air");
      tree.insert("car");
      tree.insert("duck");
      tree.insert("fire");
      tree.insert("ice");
      if(tree.root->element != "cart") return false;
      if(tree.root->left->element != "ball") return false;
      if(tree.root->right->element != "element") return false;
      if(tree.root->left->left->element != "air") return false;
      if(tree.root->left->right->element != "car") return false;
      if(tree.root->right->left->element != "duck") return false;
      if(tree.root->right->right->element != "fire") return false;
      if(tree.root->right->right->right->element != "ice") return false;
      if(tree.root->right->right->right->left != NULL) return false;
      if(tree.root->right->right->right->right != NULL) return false;
      if(tree.root->right->left->left != NULL) return false;
      if(tree.root->right->left->right != NULL) return false;
      if(tree.root->left->right->left != NULL) return false;
      if(tree.root->left->right->right != NULL) return false;
      if(tree.root->left->left->left != NULL) return false;
      if(tree.root->left->left->right != NULL) return false;
      if(tree.root->height != 3) return false;
      if(tree.root->left->height != 1) return false;
      if(tree.root->right->height != 2) return false;
      if(tree.root->left->left->height != 0) return false;
      if(tree.root->left->right->height != 0) return false;
      if(tree.root->right->left->height != 0) return false;
      if(tree.root->right->right->height != 1) return false;
      if(tree.root->right->right->right->height != 0) return false;
    }
    else if(test == 12)
    // insertions with single rotations only
    {
      AvlTree tree;
      tree.insert("element");
      tree.insert("car");
      tree.insert("ball");
      tree.insert("fire");
      tree.insert("ice");
      tree.insert("air");
      tree.insert("duck");
      tree.insert("cart");
      if(tree.root->element != "car") return false;
      if(tree.root->left->element != "ball") return false;
      if(tree.root->right->element != "fire") return false;
      if(tree.root->left->left->element != "air") return false;
      if(tree.root->right->left->element != "duck") return false;
      if(tree.root->right->right->element != "ice") return false;
      if(tree.root->right->left->left->element != "cart") return false;
      if(tree.root->right->left->right->element != "element") return false;
      if(tree.root->right->right->left != NULL) return false;
      if(tree.root->right->right->right != NULL) return false;
      if(tree.root->right->left->left->left != NULL) return false;
      if(tree.root->right->left->left->right != NULL) return false;
      if(tree.root->right->left->right->left != NULL) return false;
      if(tree.root->right->left->right->right != NULL) return false;
      if(tree.root->left->left->left != NULL) return false;
      if(tree.root->left->left->right != NULL) return false;
      if(tree.root->left->right != NULL) return false;
      if(tree.root->height != 3) return false;
      if(tree.root->left->height != 1) return false;
      if(tree.root->right->height != 2) return false;
      if(tree.root->left->left->height != 0) return false;
      if(tree.root->right->left->height != 1) return false;
      if(tree.root->right->right->height != 0) return false;
      if(tree.root->right->left->left->height != 0) return false;
      if(tree.root->right->left->right->height != 0) return false;
    }
    else if(test == 13)
    // insertions with double rotations only
    {
      AvlTree tree;
      tree.insert("air");
      tree.insert("cart");
      tree.insert("car");
      tree.insert("ball");
      tree.insert("element");
      tree.insert("duck");
      tree.insert("ice");
      tree.insert("fire");
      if(tree.root->element != "car") return false;
      if(tree.root->left->element != "air") return false;
      if(tree.root->right->element != "duck") return false;
      if(tree.root->left->right->element != "ball") return false;
      if(tree.root->right->left->element != "cart") return false;
      if(tree.root->right->right->element != "fire") return false;
      if(tree.root->right->right->left->element != "element") return false;
      if(tree.root->right->right->right->element != "ice") return false;
      if(tree.root->left->left != NULL) return false;
      if(tree.root->left->right->left != NULL) return false;
      if(tree.root->left->right->right != NULL) return false;
      if(tree.root->right->left->left != NULL) return false;
      if(tree.root->right->left->right != NULL) return false;
      if(tree.root->right->right->left->left != NULL) return false;
      if(tree.root->right->right->left->right != NULL) return false;
      if(tree.root->right->right->right->left != NULL) return false;
      if(tree.root->right->right->right->right != NULL) return false;
      if(tree.root->height != 3) return false;
      if(tree.root->left->height != 1) return false;
      if(tree.root->right->height != 2) return false;
      if(tree.root->left->right->height != 0) return false;
      if(tree.root->right->left->height != 0) return false;
      if(tree.root->right->right->height != 1) return false;
      if(tree.root->right->right->left->height != 0) return false;
      if(tree.root->right->right->right->height != 0) return false;
    }
    else if(test == 14)
    // insertions with single and double rotations
    {
      AvlTree tree;
      tree.insert("ball");
      tree.insert("fire");
      tree.insert("air");
      tree.insert("ice");
      tree.insert("element");
      tree.insert("duck");
      tree.insert("cart");
      tree.insert("car");
      if(tree.root->element != "element") return false;
      if(tree.root->left->element != "ball") return false;
      if(tree.root->right->element != "fire") return false;
      if(tree.root->left->left->element != "air") return false;
      if(tree.root->left->right->element != "cart") return false;
      if(tree.root->right->right->element != "ice") return false;
      if(tree.root->left->right->left->element != "car") return false;
      if(tree.root->left->right->right->element != "duck") return false;
      if(tree.root->left->left->left != NULL) return false;
      if(tree.root->left->left->right != NULL) return false;
      if(tree.root->left->right->left->left != NULL) return false;
      if(tree.root->left->right->left->right != NULL) return false;
      if(tree.root->left->right->right->left != NULL) return false;
      if(tree.root->left->right->right->right != NULL) return false;
      if(tree.root->right->left != NULL) return false;
      if(tree.root->right->right->left != NULL) return false;
      if(tree.root->right->right->right != NULL) return false;
      if(tree.root->height != 3) return false;
      if(tree.root->left->height != 2) return false;
      if(tree.root->right->height != 1) return false;
      if(tree.root->left->left->height != 0) return false;
      if(tree.root->left->right->height != 1) return false;
      if(tree.root->right->right->height != 0) return false;
      if(tree.root->left->right->left->height != 0) return false;
      if(tree.root->left->right->right->height != 0) return false;
    }
    else if(test == 15)
    // insertions with duplicates
    {
      AvlTree tree;
      tree.insert("ball");
      tree.insert("fire");
      tree.insert("fire");
      tree.insert("air");
      tree.insert("ice");
      tree.insert("element");
      tree.insert("ice");
      tree.insert("duck");
      tree.insert("ball");
      tree.insert("element");
      tree.insert("cart");
      tree.insert("duck");
      tree.insert("car");
      tree.insert("cart");
      tree.insert("car");
      tree.insert("air");
      if(tree.root->element != "element") return false;
      if(tree.root->left->element != "ball") return false;
      if(tree.root->right->element != "fire") return false;
      if(tree.root->left->left->element != "air") return false;
      if(tree.root->left->right->element != "cart") return false;
      if(tree.root->right->right->element != "ice") return false;
      if(tree.root->left->right->left->element != "car") return false;
      if(tree.root->left->right->right->element != "duck") return false;
      if(tree.root->left->left->left != NULL) return false;
      if(tree.root->left->left->right != NULL) return false;
      if(tree.root->left->right->left->left != NULL) return false;
      if(tree.root->left->right->left->right != NULL) return false;
      if(tree.root->left->right->right->left != NULL) return false;
      if(tree.root->left->right->right->right != NULL) return false;
      if(tree.root->right->left != NULL) return false;
      if(tree.root->right->right->left != NULL) return false;
      if(tree.root->right->right->right != NULL) return false;
      if(tree.root->height != 3) return false;
      if(tree.root->left->height != 2) return false;
      if(tree.root->right->height != 1) return false;
      if(tree.root->left->left->height != 0) return false;
      if(tree.root->left->right->height != 1) return false;
      if(tree.root->right->right->height != 0) return false;
      if(tree.root->left->right->left->height != 0) return false;
      if(tree.root->left->right->right->height != 0) return false;
      if(tree.root->height != 3) return false;
      if(tree.root->left->count != 2) return false;
      if(tree.root->right->count != 2) return false;
      if(tree.root->left->left->count != 2) return false;
      if(tree.root->left->right->count != 2) return false;
      if(tree.root->right->right->count != 2) return false;
      if(tree.root->left->right->left->count != 2) return false;
      if(tree.root->left->right->right->count != 2) return false;
    }
    else exit(1);
    return true;
  }
} insert_test;

struct test_16_20
{
  bool operator()(int test)
  {
    if(test == 16)
    // remove leaf without rotations
    {
      AvlTree tree;
      test_tree(tree.root);
      tree.remove("ice");
      if(tree.root->right->right->right != NULL) return false;
      if(tree.root->right->right->height != 0) return false;
      if(tree.root->right->height != 1) return false;
      if(tree.root->height != 2) return false;
    }
    else if(test == 17)
    // remove non-leaf without rotations
    {
      AvlTree tree;
      test_tree(tree.root);
      tree.remove("fire");
      if(tree.root->right->right->right != NULL) return false;
      if(tree.root->right->right->height != 0) return false;
      if(tree.root->right->height != 1) return false;
      if(tree.root->height != 2) return false;
    }
    else if(test == 18)
    // remove leaf with rotation
    {
      AvlTree tree;
      test_tree(tree.root);
      tree.remove("duck");
      if(tree.root->right->right->left != NULL) return false;
      if(tree.root->right->right->right != NULL) return false;
      if(tree.root->right->left->left != NULL) return false;
      if(tree.root->right->left->right != NULL) return false;
      if(tree.root->right->left->height != 0) return false;
      if(tree.root->right->right->height != 0) return false;
      if(tree.root->right->height != 1) return false;
      if(tree.root->height != 2) return false;
    }
    else if(test == 19)
    // remove non-leaf with rotation
    {
      AvlTree tree;
      test_tree(tree.root);
      tree.remove("cart");
      if(tree.root->element != "duck") return false;
      if(tree.root->right->element != "fire") return false;
      if(tree.root->right->left->element != "element") return false;
      if(tree.root->right->right->element != "ice") return false;
      if(tree.root->right->right->left != NULL) return false;
      if(tree.root->right->right->right != NULL) return false;
      if(tree.root->right->left->left != NULL) return false;
      if(tree.root->right->left->right != NULL) return false;
      if(tree.root->right->left->height != 0) return false;
      if(tree.root->right->right->height != 0) return false;
      if(tree.root->right->height != 1) return false;
      if(tree.root->height != 2) return false;
    }
    else if(test == 20)
    // remove duplicate
    {
      AvlTree tree;
      test_tree(tree.root);
      tree.root->right->count++;
      tree.remove("element");
      if(tree.root->height != 3) return false;
      if(tree.root->right->height != 2) return false;
      if(tree.root->right->count != 1) return false;
    }
    else exit(1);
    return true;
  }
} remove_test;

//struct test_14_15
//{
//  bool operator()(int test)
//  {
//    SortedArrayList list;
//    list.buf = new string[5];
//    list.capacity = 5;
//    list.buf[0] = "Airplane";
//    list.buf[1] = "atom";
//    list.buf[2] = "yoyo";
//    list.size = 3;
//    if(test == 14) if(!list.find(string("atom"))) return false;
//    else if(test == 15) if(list.find(string("zebra"))) return false;
//    else exit(1);
//    return true;
//  }
//} find_test;
//
//struct test_16_17
//{
//  bool operator()(int test)
//  {
//    SortedArrayList list;
//    list.buf = new string[5];
//    list.capacity = 5;
//    if(test == 16) {list.size = 4; if(list.isFull()) return false;}
//    else if(test == 17) {list.size = 5; if(!list.isFull()) return false;}
//    else exit(1);
//    return true;
//  }
//} isFull_test;
//
//struct test_18_19
//{
//  bool operator()(int test)
//  {
//    SortedArrayList list;
//    list.buf = new string[5];
//    list.capacity = 5;
//    if(test == 18) {list.size = 4; if(list.isEmpty()) return false;}
//    else if(test == 19) {list.size = 0; if(!list.isEmpty()) return false;}
//    else exit(1);
//    return true;
//  }
//} isEmpty_test;
//
//struct test_20_22
//{
//  bool operator()(int test)
//  {
//    const int LENGTH = 512;
//    const double TIMEOUT = 600; // 10 minutes
//    char * word = new char[LENGTH];
//    double time;
//    Timer timer;
//    ifstream in;
//    SortedArrayList list;
//    list.buf = new string[CAPACITY];
//    list.capacity = CAPACITY;
//    list.size = 0;
//    if(test == 20)
//    {
//      in.open("random.txt");
//      while(!in.eof())
//      {
//        in.getline(word, LENGTH);
//        timer.start();
//        list.insert(string(word));
//        timer.stop();
//        if(timer.cumulativeTime() > TIMEOUT) return false;
//      }
//      in.close();
//      time = timer.cumulativeTime();
//      cout << "array insert " << time << endl;
//    }
//    else if(test == 21)
//    {
//      size_t i = 0;
//      in.open("sorted.txt");
//      while(!in.eof())
//      {
//        in.getline(word, LENGTH);
//        list.buf[i++] = string(word);
//        ++list.size;
//      }
//      in.close();
//      in.clear();
//      in.open("random.txt");
//      while(!in.eof())
//      {
//        in.getline(word, LENGTH);
//        timer.start();
//        list.find(string(word));
//        timer.stop();
//        if(timer.cumulativeTime() > TIMEOUT) return false;
//      }
//      in.close();
//      time = timer.cumulativeTime();
//      cout << "array find " << time << endl;
//    }
//    else if(test == 22)
//    {
//      size_t i = 0;
//      in.open("sorted.txt");
//      while(!in.eof())
//      {
//        in.getline(word, LENGTH);
//        list.buf[i++] = string(word);
//        ++list.size;
//      }
//      in.close();
//      in.clear();
//      in.open("random.txt");
//      while(!in.eof())
//      {
//        in.getline(word, LENGTH);
//        timer.start();
//        list.remove(string(word));
//        timer.stop();
//        if(timer.cumulativeTime() > TIMEOUT) return false;
//      }
//      in.close();
//      time = timer.cumulativeTime();
//      cout << "array remove " << time << endl;
//    }
//    else exit(1);
//    return true;
//  }
//} timing_test;
//
//struct sort_t
//{
//  void operator()()
//  {
//    char word[512];
//    ifstream in("random_short.txt");
//    SortedArrayList list;
//    in.getline(word, 512);
//    while(!in.eof())
//    {
//      list.insert(string(word));
//      in.getline(word, 512);
//    }
//    in.close();
//    ofstream out("sorted_short.txt");
//    for(size_t i = 0; i != list.size; ++i) out << list.buf[i] << endl;
//    out.close();
//  }
//} sort;
