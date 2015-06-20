#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

#define KEY_NOT_FOUND 0
#define HASH_FULL 1

class HashOb
{
public:
   string key;
   string val;

   HashOb(string& key, string& val) {this->key = key; this->val = val;}
   HashOb() {key = ""; val = "";}
};

template<class T> struct Node
{
   T* item;
   Node* next;
};

template<class T> class LinkedList
{
public:
  Node<T>* head;
  Node<T>* tail;
  int size;

  LinkedList() {head = NULL; size = 0;}

  void add(Node<T>* node)
  {
    if(head == NULL) {head = node; tail = node;}
    else {tail->next = node; tail = node;}
    size++;
  }

  void remove(Node<T>* node)
  {
    if(node == head)
    {
      if(head == tail) {head = NULL; tail = NULL;}
      else head = head->next;
    }
    else
    {
      Node<T>* temp = head;
      while(temp->next != node) temp = temp->next;
      temp->next = node->next; 
    }
    node->next = NULL;
    delete node;
    size--;
  }
};

class HashTable
{
protected:
  int capacity;
  
  HashTable(int capacity) {this->capacity = capacity;}
  int hash(const string& key)
  {
    int hval = 0;
    
    for(size_t i = 0; i < key.length(); i++)
      hval += static_cast<int>(key[i]);
    hval = hval % capacity;
    return hval;
  }

public:
  virtual string find(string) = 0;
  virtual void put(string, string) = 0;
  virtual void print() = 0;
};

class LinearHash : public HashTable
{
private:
  //Array of pointers to HashObs
  HashOb** table;
public:
  LinearHash(int capacity) : HashTable(capacity)
  {
    table = new HashOb*[capacity];
    for(int i = 0; i < capacity; i++) table[i] = NULL;
   }
//--------------------------------------------------------------------------------
// This function takes a key and:
//    If the key exists, return the value of that key
//    If the key doesn't exist, throw KEY_NOT_FOUND
//
// Remember that this is Linear Probing Hash. Hash collision can occur.
// You MUST check if the index retrieved by your hash function contains the
// RIGHT KEY
//--------------------------------------------------------------------------------
  virtual string find(string key)
  {
    int index = hash(key);
    int sent = 0;
    while( sent != 2 )
    {
      if(index >= capacity)
      {
        sent++;
        index = 0;
        if(sent == 2)
        {
          throw KEY_NOT_FOUND;
        }
      }
        
      if(this->table[index] == NULL)
      {
        throw KEY_NOT_FOUND;
      }
      if( this->table[index]->key == key)
      {
        return this->table[index]->key;
      }
      index++;
    }
  }
//--------------------------------------------------------------------------------
// This function takes a key, value pair and:
//    If the key exists, REPLACE the value of that key with the new VALUE
//    If the key doesn't exist, create new entry in the table
//    If the hash is FULL, throw HASH_FULL
//
// Remember that this is Linear Probing Hash. Hash collision can occur.
// You MUST check if the index retrieved by your hash function contains the
// an EXISTING object with a different key. If it does, you must probe
// linearly until:
//    You KNOW that the table is full, then throw HASH_FULL error
//    You find an empty slot
//--------------------------------------------------------------------------------
  virtual void put(string key, string value)
  {
    int index = hash(key);
    int sent = 0;
    while( sent != 2 )
    {
      if(index >= capacity)
      {
        sent++;
        index = 0;
        if(sent == 2)
        {
          throw HASH_FULL;
        }
      }
        
      if(this->table[index] == NULL)
      {
        HashOb* temp = new HashOb(key,value);
        this->table[index] = temp;
        return;
      }
      if( this->table[index]->key == key)
      {
        this->table[index]->val = value;
        return;
      }
      index++;
    }
      
  }

  virtual void print()
  {
    for(int i = 0; i < capacity; i++)
      if(table[i] != NULL)
      {
        cout << setw(20) << table[i]->key;
        cout << setw(20) << table[i]->val << endl;
      }
  }
};

class ChainedHash : public HashTable
{
private:
   //Array of pointers to LinkedLists
   LinkedList<HashOb>** table;
public:
  ChainedHash(int capacity) : HashTable(capacity)
  {  
    table = new LinkedList<HashOb>*[capacity];
    for(int i = 0; i < capacity; i++) table[i] = new LinkedList<HashOb>();
  }
//--------------------------------------------------------------------------------
// This function takes a key, value pair and:
//    If the key exists, REPLACE the value of that key with the new VALUE
//    If the key doesn't exist, create new entry in the table
//
// Remember that this is Chained Hash. Hash collision can occur.
// You MUST check if the index retrieved by your hash function contains the
// an EXISTING object with a different key. If it does, you must
// create a new Node in that LinkedList and add it in.
//--------------------------------------------------------------------------------
  virtual void put(string key, string value)
  {
    int index = hash(key);
    if(this->table[index]->head == NULL)
    {
      HashOb* temp = new HashOb(key,value);
      Node<HashOb>* temp2 = new Node<HashOb>;
      temp2->item = temp;
      temp2->next = NULL;
      this->table[index]->add(temp2);
    }
    else
    {
      Node<HashOb>* temp = this->table[index]->head;
      while(temp != NULL)
      {
        if(temp->item->key == key)
        {
          temp->item->val = value;
          return;
        }
        temp = temp->next;
      }
      HashOb* temp3 = new HashOb(key,value);
      Node<HashOb>* nt = new Node<HashOb>;
      nt->item = temp3;
      nt->next = NULL;
      this->table[index]->add(nt);
    }
      
  }
//--------------------------------------------------------------------------------
// This function takes a key and:
//    If the key exists, return the value of that key
//    If the key doesn't exist, throw KEY_NOT_FOUND
//
// Remember that this is Chained Hash. Hash collision can occur.
// You MUST check if the Linked List in the index retrieved by your hash function 
// contains the RIGHT KEY
//--------------------------------------------------------------------------------
  virtual string find(string key)
  {
    
    int index = hash(key);
    if(this->table[index]->head == NULL)
    {
      throw KEY_NOT_FOUND;
    }
    else
    {
      Node<HashOb>* temp = this->table[index]->head;
      while(temp != NULL)
      {
        if(temp->item->key == key)
        {
          return temp->item->key;
        }
        temp = temp->next;
      }
      throw KEY_NOT_FOUND;
    }
      
  }

  virtual void print()
  {
    for(int i = 0; i < capacity; i++)
      if(table[i]->size != 0)
      {
        Node<HashOb>* temp = table[i]->head;
        cout << "Index " << i << endl;
        while(temp != NULL)
        {
          cout << setw(20) << temp->item->key;
          cout << setw(20) << temp->item->val << endl;
          temp = temp->next;
        }
      }
  }
};

