// Course: CS 14 Spring 2012
// 
// First Name: samuel
// Last Name: villarreal
// UCR Username: svill017 
// UCR Email Address: svill017@ucr.edu
// 
// Lecture Section: 001
// Lab Section: 021
// TA: Krystof Litomisky
// 
// Assignment: assignment 3
// 
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
// 
// ===========================================================================

#include "Timer.h"
#include "SortedLinkedList.h"

using namespace std;

SortedLinkedList::SortedLinkedList() : head(NULL) {}

SortedLinkedList::SortedLinkedList(const SortedLinkedList & source)
: SortedList(), head(NULL)
{
  if(source.head == NULL) return;
  head = new ListNode(source.head->word);
  ListNode * thisNode = head;
  ListNode * sourceNode = source.head->next;
  while(sourceNode != NULL)
  {
    thisNode->next = new ListNode(sourceNode->word);
    thisNode = thisNode->next;
    sourceNode = sourceNode->next;
  }
}

SortedLinkedList::~SortedLinkedList() {destroy_list();}

SortedLinkedList & SortedLinkedList::operator =(const SortedLinkedList & rhs)
{
  if(this == &rhs) return *this;
  destroy_list();
  create_list(rhs);
  return *this;
}

void SortedLinkedList::insert(const string & word)
{
  if(isFull())
  {
    cerr << "error is full";
    return;
  }
  else if(isEmpty())
  {
    head = new ListNode;
    head->word = word;
    head->next = NULL;
  }
  else
  {
    ListNode* p = head;
    while( lessThan(p->word,word) && p->next != NULL)
    {
      p=p->next;
    }
    p->next = new ListNode(word,p->next);
  }
    
// *** REPLACE WITH YOUR IMPLEMENTATION ***
}

bool SortedLinkedList::find(const string & word) const
{
  ListNode* p = head;
  while(p->next)
  {
    if(p->word == word) return true;
    p= p->next;
  }
  return false;
// *** REPLACE WITH YOUR IMPLEMENTATION ***
}

void SortedLinkedList::remove(const string & word)
{
  if( isEmpty()) return;
  
  if(head->word == word)
  {
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return;
  }
  
  ListNode* p = head;
  ListNode* pre= NULL;
  while(p->word != word)
  {
  pre = p;
  p = p->next;
  if(!p)
  {
    delete pre ->next;
    pre->next = NULL;
    return;
  }
  }
  if(p->word != word) return;

  pre->next = p->next;
  
    delete p;
  
    
// *** REPLACE WITH YOUR IMPLEMENTATION ***
}

void SortedLinkedList::create_list(const SortedLinkedList & source)
{
  if(source.head == NULL) return;
  head = new ListNode(source.head->word);
  ListNode * current = head->next;
  for(ListNode * p = source.head->next; p != NULL; p = p->next)
  {current = new ListNode(p->word); current = current->next;}
}

void SortedLinkedList::destroy_list()
{
  while(head!= NULL)
  {
    ListNode * current = head;
    head = head->next;
    delete current;
  }
}
