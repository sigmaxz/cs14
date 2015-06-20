#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include "lab06header.h"

using namespace std;

void ex01()///////////////////////////////////////////////////////////////////
{
   ChainedHash* ch = new ChainedHash(3);
   
   try
   {
      ch->put("stoneage","stone");
      ch->put("anagrams","arsmagna");
      ch->put("stageone","stage");
      ch->put("debit card","debit");
      ch->put("bad credit","credit");
      ch->put("evil","T.A.");
      ch->put("evil","live");
   }
   catch(int)
   {
      cerr << "Exception, not supposed to happen." << endl;
   }
   
   cout << "********************Exercise 01*************************" << endl;
   cout << "*************What your output should look like**********" << endl;
   cout << endl;
   cout << "Index 0" << endl;
   cout << setw(20) << "evil";       cout << setw(20) << "live"      << endl;
   cout << "Index 2" << endl;
   cout << setw(20) << "stoneage";   cout << setw(20) << "stone"     << endl;
   cout << setw(20) << "anagrams";   cout << setw(20) << "arsmagna"  << endl;
   cout << setw(20) << "stageone";   cout << setw(20) << "stage"     << endl;
   cout << setw(20) << "debit card"; cout << setw(20) << "debit"     << endl;
   cout << setw(20) << "bad credit"; cout << setw(20) << "credit"    << endl;
   
   cout << endl;
   cout << "**********What your output actually looks like**********" << endl;
   cout << endl;
   ch->print();
   cout << endl;
   cout << "********************************************************" << endl;
}/////////////////////////////////////////////////////////////////////////////

void ex02()///////////////////////////////////////////////////////////////////
{
   LinearHash* lh = new LinearHash(5);
   
   try
   {
      lh->put("stoneage","stone");
      lh->put("stageone","stage");
      lh->put("debit card","debit");
      lh->put("bad credit","credit");
      lh->put("evil","T.A.");
      lh->put("evil","live");
   }
   catch(int)
   {
      cerr << "Exception, not supposed to happen." << endl;
   }
   cout << endl;
   cout << "********************Exercise 02*************************" << endl;
   cout << "*************What your output should look like**********" << endl;
   cout << endl;
   cout << setw(20) << "stageone";   cout << setw(20) << "stage"  << endl;
   cout << setw(20) << "evil";       cout << setw(20) << "live"   << endl;
   cout << setw(20) << "debit card"; cout << setw(20) << "debit"  << endl;
   cout << setw(20) << "bad credit"; cout << setw(20) << "credit" << endl;
   cout << setw(20) << "stoneage";   cout << setw(20) << "stone"  << endl;
   cout << endl;
   cout << "**********What your output actually looks like**********" << endl;
   cout << endl;
   lh->print();
   cout << endl;
   cout << "********************************************************" << endl;
   
   try
   {
      lh->put("entry","entry");
   }
   catch(int i)
   {
      if(i == HASH_FULL)
      {
         cout << "HASH-FULL exception expected. Exercise SUCCEEDS." << endl;
         cout << "************************************" 
              << "***********************" << endl;
      }
      else
      {
         cout << "Unexpected exception code. Exercise FAILS." << endl;
         cout << "************************************" 
              << "***********************" << endl;
      }
      
      return;
   }
   
   cout << "Expected exception did not arrive. Exercise FAILS." << endl;
   cout << "************************************" 
        << "***********************" << endl;
   
}/////////////////////////////////////////////////////////////////////////////

void ex03()///////////////////////////////////////////////////////////////////
{
   LinearHash* lh = new LinearHash(5);
   
   try
   {
      lh->put("stoneage","stone");
      lh->put("stageone","stage");
      lh->put("debit card","debit");
      lh->put("bad credit","credit");
      lh->put("evil","T.A.");
      lh->put("evil","live");
   }
   catch(int)
   {
      cerr << "Exception, not supposed to happen." << endl;
   }
   
   cout << endl;
   cout << "**********************Exercise 03***********************" << endl;
   string result    = lh->find("stageone");
   string predicted = "stage";
   
   if(result.compare(predicted) == 0)
   {
      cout << "Look-up SUCCEEDDS" << endl;
   }
   else
   {
      cout << "Look-up FAILS" << endl;
   }
   
   cout << "Predicted: " << predicted << endl;
   cout << "Actual:    " << result << endl;
   
   try
   {
      lh->find("live");
   }
   
   catch(int i)
   {
      if(i == KEY_NOT_FOUND)
      {
        cout << "KEY_NOT_FOUND exception anticipated. Look-up SUCCEEDS";
        cout << endl;
      }
      else
         cout << "Unknown exception uannticipated. Look-up FAILS" << endl;
         
      cout << "************************************" 
           << "***********************" << endl;
         
      return;
   }
   
   cout << "KEY_NOT_FOUND exception did not arrive. Look-up FAILS" << endl;
   cout << "************************************" 
        << "***********************" << endl;
   
}/////////////////////////////////////////////////////////////////////////////

void ex04()///////////////////////////////////////////////////////////////////
{
   ChainedHash* ch = new ChainedHash(25);
   
   try
   {
      ch->put("stoneage","stone");
      ch->put("stageone","stage");
      ch->put("debit card","debit");
      ch->put("bad credit","credit");
      ch->put("evil","T.A.");
      ch->put("evil","live");
   }
   catch(int)
   {
      cerr << "Exception, not supposed to happen." << endl;
   }
   
   cout << endl;
   cout << "***********************Exercise 04*************************" << endl;
   string result    = ch->find("stageone");
   string predicted = "stage";
   
   if(result.compare(predicted) == 0)
   {
      cout << "Look-up SUCCEEDDS" << endl;
   }
   else
   {
      cout << "Look-up FAILS" << endl;
   }
   
   cout << "Predicted: " << predicted << endl;
   cout << "Actual:    " << result << endl;
   
   try
   {
      ch->find("evilta");
   }
   
   catch(int i)
   {
      if(i == KEY_NOT_FOUND)
         cout << "KEY_NOT_FOUND exception anticipated. Look-up SUCCEEDS" << endl;
      else
         cout << "Unknown exception uannticipated. Look-up FAILS" << endl;
         
      cout << "************************************" 
           << "***********************" << endl;
         
      return;
   }
   
   cout << "KEY_NOT_FOUND exception did not arrive. Look-up FAILS" << endl;
   cout << "************************************" 
        << "***********************" << endl;
}/////////////////////////////////////////////////////////////////////////////

int main()
{
   int choice = -1;
   
    while(choice != 0)
    {
       cout << "Enter exercise number: ";
       cin >> choice;

       switch(choice)
       {
          case 1: ex01(); break;
          case 2: ex02(); break;
          case 3: ex03(); break;
          case 4: ex04(); break;
       }
    }

   return 0;
}