// Course: CS 14 Spring 2012
// 
// First Name: Samuel
// Last Name: Villarreal
// UCR Username: svill017
// UCR Email Address: svill017@ucr.edu
// 
// Lecture Section: 001
// Lab Section: 021
// TA: Krystof Litomisky
// 
// Assignment: assignment 4
// 
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
// 
// ===========================================================================

#ifndef CONTAINERUNDERFLOW_H
#define CONTAINERUNDERFLOW_H

#include <iostream>
using namespace std;

class ContainerUnderflow
{
public:
  string err;
  ContainerUnderflow(string s)
  :err(s) {}
  std::string what() const
  {
    return err;
  }
  
};

#endif
