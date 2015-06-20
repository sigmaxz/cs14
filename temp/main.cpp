#include <iostream>
using namespace std;
int main()
{
string stuff;
char list;
int c = 0;
string temp;

cin >> stuff; 
cout << stuff << endl;
cin >> stuff; 
cout << stuff << endl;
cin >> stuff; 
for(int i = 0; i < stuff.size(); i++)
{
if( stuff[i] == ',')
{
	cout << temp << endl;
	temp.clear();
}
else 
	temp += stuff[i];
}
	

return 0; 
}
	
