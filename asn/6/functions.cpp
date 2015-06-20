#include "Pair.h"

using namespace std;

bool is_prime(int n)
{
  if(n == 2 || n == 3) return true;
  if(n == 1 || n % 2 == 0) return false;
  for(int i = 3; i * i <= n; i += 2) if(n % i == 0) return false;
  return true;
}

int next_prime(int n)
{
  if(n <= 0) n = 3;
  if(n % 2 == 0) n++;
  for( ; !is_prime(n); n += 2);
  return n;
}

int hash(const string & key)
{
  int hash_val = 0;
  for(int i = 0; i < (int)key.length(); i++)
    hash_val = 37 * hash_val + key[i];
  return hash_val;
}

int hash(int key)
{return key;}

int hash(const Pair<string, string> & x)
// Precondition: none
// Postcondition: Return value is... (you must figure it out)
{
  return hash(x.get_key());
}
