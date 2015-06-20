// Course: CS 14 spring 2012
//
// First Name: samuel
// Last Name: villarreal
// UCR Username: svill017
// UCR Email Address: svill017@ucr.edu
//
// Lecture Section: 001
// Lab Section: 021
// TA: Krystof L
//
// Assignment: lab 9
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ============================================================================
#include <assert.h>

#include <iostream>

#include "MyString.h"

using namespace std;


bool lessThan(std::string lhs, std::string rhs);
// Precondition: none
// Postcondition: Return true if rhs follows lhs lexicographycally,
// case insensitive
  

void lessThanTest();
// tests the less than function


void giveHalfTest();
// 


int main()
{
	lessThanTest();
	cout << "\nlessThan() tests passed.\n\n";

	giveHalfTest();
	cout << "giveHalf() didn't crash.\n";
}


void giveHalfTest()
{	
	MyString s("a1c2b3d4e5f6");
	MyString even;
	s.giveHalf(&even);

	cout << "letters: " << s << endl;
	cout << "numbers: " << even << endl;

	MyString s2;
	s2.giveHalf(&even); //do you get a segfault?
}

void lessThanTest()
{
	assert(lessThan(string("abc"), string("abc")) == false );
	assert(lessThan(string("Abc"), string("abc")) == false );
	assert(lessThan(string("abcd"), string("abc")) == false );
	assert(lessThan(string("abc"), string("AbCd")) == true );
	assert(lessThan(string("abc"), string("bc")) == true );
	assert(lessThan(string("abc"), string("efghij")) == true );
}

bool lessThan(std::string lhs, std::string rhs)
// Precondition: none
// Postcondition: Return true if rhs follows lhs lexicographycally,
// case insensitive
{
  const int SLENGTH = 1;
  const int LEX_LIMIT = 90;
  const int LEX_DIF = 32;
  
  int position = 0;
  
  for (; position < lhs.size() && position < rhs.size() ; position++)
  {
      char lhs_char= lhs[position];
      char rhs_char= rhs[position];
      if (lhs_char<= LEX_LIMIT ) lhs_char+= LEX_DIF;
      if (rhs_char<= LEX_LIMIT) rhs_char+= LEX_DIF;

      if(lhs_char< rhs_char) return true;
      if( lhs_char> rhs_char) return false;

  }
  if(position == lhs.size() && position < rhs.size() ) return true;
  return false;
}
