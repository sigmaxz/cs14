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
    ListNode* temp = new ListNode(word,head);
    ListNode* pre = NULL;
    ListNode* t2 = NULL;
    head = temp;
    if(!lessThan(temp->word,temp->next->word))return;
    while( temp->next && lessThan(temp->word,temp->next->word) )
    {
      if(temp == head)
      {
        head = temp->next;
        pre = temp->next;
      }
      t2 = temp->next;
      temp->next = temp->next->next;
      t2->next = temp;
      pre->next = t2;
      pre = t2;
    }
    //ListNode* p = head;
    //ListNode* temp = NULL;
    //while( !lessThan(p->word,word) && p->next != NULL)
    //{
      //temp = p;
      //p=p->next;
    //}
    //if( p == head && lessThan(head->word,word)) head = new ListNode(word,head);
    //else if( p->next == NULL && !lessThan(p->word,word)) p->next = new ListNode(word,NULL);
    //else
    //temp->next= new ListNode(word,p);
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
