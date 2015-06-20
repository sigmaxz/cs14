#include "MyStringTests.h"

using namespace std;

int main(int argc, char ** argv)
{
  //if(argc != 2)
  //{cerr << "usage: " << argv[0] << " test_number" << endl; exit(1);}

  //int test = atoi(argv[1]);
  int test;

  ofstream out("result.txt");

  if(test = 1)
  {
    if(default_constructor_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 2)
  {
    if(single_parameter_constructor_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 3)
  {
    if(copy_constructor_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 4)
  {
    if(copy_constructor_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 5)
  {
    if(destructor_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 6)
  {
    if(assignment_operator_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 7)
  {
    if(assignment_operator_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 8)
  {
    if(index_operator_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 9)
  {
    if(index_operator_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 10)
  {
    if(index_operator_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 11)
  {
    if(length_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 12)
  {
    if(length_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 13)
  {
    if(indexOf_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 14)
  {
    if(indexOf_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 15)
  {
    if(indexOf_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 16)
  {
    if(operator_equals_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 17)
  {
    if(operator_equals_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 18)
  {
    if(operator_equals_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 19)
  {
    if(operator_equals_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 20)
  {
    if(operator_equals_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 21)
  {
    if(operator_plus_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 22)
  {
    if(operator_plus_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 23)
  {
    if(operator_plus_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 24)
  {
    if(operator_plus_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 25)
  {
    if(operator_plus_equals_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 26)
  {
    if(operator_plus_equals_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 27)
  {
    if(operator_plus_equals_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 28)
  {
    if(operator_plus_equals_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 29)
  {
    if(reverse_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 30)
  {
    if(reverse_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 31)
  {
    if(reverse_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 32)
  {
    if(reverse_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 33)
  {
    if(read_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test = 34)
  {
    if(print_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  return 0;
}
