#include <iostream>
#include <vector>

using namespace std;

class sin
{
  private:
   sin(){}
   static sin* s;
   sin(const sin& s ){}
   
  public:
    static sin& get_ins()
    {
      if(s == NULL) s = new sin();
      return *s
    }

};
