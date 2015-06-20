#include <iostream>
#include <fstream>
#include "Dictionary.h"

using namespace std;

int main()//int argc, char ** argv)
{
  Dictionary<string, string> d;

  // auger, succinct and drab hash to same cell in a table of size 7

  cerr << "empty? " << d.is_empty() << endl;

  cerr << "---------" << endl;
  d.print(cerr);
  cerr << "---------" << endl;
  d.insert("succinct", "briefly and clearly expressed");
  cerr << "---------" << endl;
  d.print(cerr);
  cerr << "---------" << endl;
  d.insert("vincit omnia veritas", "truth conquers all things ");
  cerr << "---------" << endl;
  d.print(cerr);
  cerr << "---------" << endl;
  d.insert("austere", "stern and cold in appearance or manner");
  cerr << "---------" << endl;
  d.print(cerr);
  cerr << "---------" << endl;
  d.insert("bona fide", "made in good faith without fraud or deceit");
  cerr << "---------" << endl;
  d.print(cerr);
  cerr << "---------" << endl;
  d.insert("auger", "a tool with a helical bit for boring holes in wood");
  cerr << "---------" << endl;
  d.print(cerr);
  cerr << "---------" << endl;
  d.insert("drab", "lacking brightness or interest");
  cerr << "---------" << endl;
  d.print(cerr);
  cerr << "---------" << endl;

  string term;

  term = "drab";
  cerr << term << ": ";
  try
  {
    string def = d.lookup(term);
    cerr << def << endl;
  }
  catch(NotFoundException e)
  {
    cerr << e.what() << endl;
  }
  cerr << endl;

  term = "succinct";
  d.remove(term);
  cerr << "---------" << endl;
  d.print(cerr);
  cerr << "---------" << endl;
  cerr << term << ": ";
  try
  {
    string def = d.lookup(term);
    cerr << def << endl;
  }
  catch(NotFoundException e)
  {
    cerr << e.what() << endl;
  }
  cerr << endl;

  term = "drab";
  cerr << term << ": ";
  try
  {
    string def = d.lookup(term);
    cerr << def << endl;
  }
  catch(NotFoundException e)
  {
    cerr << e.what() << endl;
  }
  cerr << endl;

  return 0;

  term = "austere";
  cerr << term << ": ";
  try
  {
    string def = d.lookup(term);
    cerr << def << endl;
  }
  catch(NotFoundException e)
  {
    cerr << e.what() << endl;
  }
  cerr << endl;

  term = "pacify";
  cerr << term << ": ";
  try
  {
    string def = d.lookup(term);
    cerr << def << endl;
  }
  catch(NotFoundException e)
  {
    cerr << e.what() << endl;
  }
  cerr << endl;

  term = "car";
  cerr << term << ": ";
  try
  {
    string def = d.lookup(term);
    cerr << def << endl;
  }
  catch(NotFoundException e)
  {
    cerr << e.what() << endl;
  }
  cerr << endl;

  cerr << d.is_empty() << endl;

  //cerr << endl << "String Hashing" << endl << endl;
  //ifstream in("sorted_short.txt");
  //vector<string> words;
  //vector<int> hashes;
  //string word;
  //while(in >> word)
  //{
  //  words.push_back(word);
  //  int hash_val = hash(word) % 17;
  //  if(hash_val < 0) hash_val = hash_val + 17;
  //  hashes.push_back(hash_val);
  //}
  //vector<vector<string> > duplicates(words.size());
  //for(int i = 0; i != (int)words.size() - 1; ++i)
  //{
  //  vector<string> dup;
  //  for(int j = i + 1; j != (int)words.size(); ++j)
  //  {
  //    if(hashes[i] == hashes[j])
  //    {
  //      dup.push_back(words[j]);
  //    }
  //  }
  //  if(!dup.empty()) duplicates[i] = dup;
  //}
  //for(int i = 0; i != (int)words.size(); ++i)
  //{
  //  if(!duplicates[i].empty())
  //  {
  //    cerr << words[i];
  //    for(int j = 0; j != (int)duplicates[i].size(); ++j)
  //      cerr << " " << duplicates[i][j];
  //    cerr << endl;
  //    break;
  //  }
  //}

  return 0;
}
