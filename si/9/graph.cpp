#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct gnode
{
  string data;
};

struct connections
{

  int weight;
  gnode* start;
  gnode* end;
};

bool connected(string a, string b)
{
  int diff = 0;
  if( a.size() != b.size()) return false; // only for equal sized strings
  for (int i = 0; i < a.size(); i++)
  {
    if( a.substr(i,1) != b.substr(i,1) ) diff++;
  }
  if( diff > 1 ) return false;
  return true;
}

class sigraph
{
  private:
    map< string, vector<gnode*> > al;
    set<string> keys;
    map< string, vecotor<gnode*> > con;
  
  public:
    
    sigraph(){}
    void add(gnode word,gnode word2,bool yes)
    {
      keys.insert(word.data);
      if(yes == false) return;
      al[word.data].push_back(&word2);
    }
    
    void add_weight()
    {
      for (int i = 0; i < ; i++)
      {
        
      }
      
    
    void  print()
    {
      map<string,vector<gnode*> >::iterator it;
      
      for (it= al.begin(); it != al.end() ; it++)
      {
        //printsub(it);
        cout << (*it).first ;
        for (int i = 0 ; i < it->second.size() ; i++)
        {
          cout << " " << it->second[i]->data << " " ;
        }
        cout << endl;
      }
    }
};
  
    
int main()
{
  gnode a;
  gnode b;
  gnode c;
  a.data = "boy";
  b.data = "bob";
  c.data = "toy";
  sigraph temp;
  
  temp.add(a,b, connected(a.data,b.data));
  temp.add(a,c, connected(a.data,c.data));
  temp.add(b,c, connected(b.data,c.data));
  temp.add(b,a, connected(b.data,a.data));
  temp.add(c,a, connected(c.data,a.data));
  temp.add(c,b, connected(c.data,b.data));
  
  temp.print();
  return 0;
}
    
  
