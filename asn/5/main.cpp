#include <fstream>
#include "AvlTree.h"
#include "AvlTreeTests.h"

using namespace std;

int main(int argc, char ** argv)
{
  if(argc != 2)
  {cerr << "usage: " << argv[0] << " test_number" << endl; exit(1);}

  int test = atoi(argv[1]);

  ofstream out("result.txt");

  if(test == 1)
  {
    if(default_constructor_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 2)
  {
    if(copy_constructor_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 3)
  {
    if(copy_constructor_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 4)
  {
    if(destructor_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 5)
  {
    if(assignment_operator_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 6)
  {
    if(assignment_operator_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 7)
  {
    if(contains_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 8)
  {
    if(contains_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 9)
  {
    if(printTree_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 10)
  {
    if(insert_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 11)
  {
    if(insert_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 12)
  {
    if(insert_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 13)
  {
    if(insert_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 14)
  {
    if(insert_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 15)
  {
    if(insert_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 16)
  {
    if(remove_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 17)
  {
    if(remove_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 18)
  {
    if(remove_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 19)
  {
    if(remove_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 20)
  {
    if(remove_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  return 0;
}
