#include <iostream>

using namespace std;

struct Node 
 { 
 typedef int value_type; 
 value_type value; 
 Node * next,* prev; 
 Node(value_type zvalue, Node * znext, Node * zprev) 
 : value(zvalue), next(znext), prev(zprev) 
 { /* empty */ } 
 }; 
 
 class LinkedList 
 { 
   size_t size_; 
   Node * head_,* tail_; 
   int numAllocations_; 
   static Node * allocate()
   {
     Node* temp = new Node();
     numAllocations_++;
     return temp;
   } 
   static void deallocate(Node * zhead)
   {
     delete zhead;
     numAllocations_--;
   } 
   
   public: 
   typedef Node::value_type value_type; 
   
   size_t size() const
   {
     return size_;
   }
   
   Node * begin()
   {
     return head_;
   }
   const Node * begin() const
   {
     return const head_;
   }
   
   Node * end()
   {
     return tail_;
   }
   const Node * end() const
   {
     return tail_;
   } 
   
   void push_front(value_type zvalue)
   {
     Node* temp = allocate();
     temp->value = zvalue;
     if(head_ == NULL )
     {
       head_= temp;
       tail_ = temp;
     }
     else
     {
       head_->prev = temp;
       temp_->next = head_;
       head_ = temp;
     }
   } 
   void push_back(value_type zvalue)
   {
     
   } 
   
   void pop_front(); 
   void pop_back(); 
   
   void erase(Node * znode); 
   void erase(Node * zfirst, Node * zlast); 
   };
   
   int main()
   {
     return 0;
   }
   
