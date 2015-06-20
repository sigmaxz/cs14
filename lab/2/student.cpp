#include <iostream>
#include <map>

using namespace std;

class Student
{
   
public:
 Student() { grade = 0 ; fname = " " ; lname = " " ; }
 int grade;
 string fname ; // f i r s t name
 string lname ; // l a s t name
} ;

int main()
{
  map<string,Student> m;
  map<string,Student>::iterator it;
  
  string username;
  int grade;
  string fname;
  string lname;
  
  do
  {
    cout << "Enter username('-1')";
    cin >> username;
    if( username != "-1")
    {
      cout << "grade (space) fname (space) lname :";
      cin >> grade >> fname >> lname;
      Student s;
      s.grade = grade;
      s.fname = fname;
      s.lname = lname;
      m[username] = s;
    }
  } while(username != "-1");
  
   for ( it = m.begin() ; it != m.end(); it++ )
   {
    cout << it->second.fname << " " << it->second.lname <<  " " << 
    (*it).first << " :" << it->second.grade << endl;
   }  
    
  return 0;
}
