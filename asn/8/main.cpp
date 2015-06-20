#include <iostream>     // provides: cout
#include <fstream>      // provides: ofstream
#include <vector>       // procides: vector

#include "Dijkstra.h"

using namespace std;

std::vector<Vertex *> graph_9_20()
{
  // create array of vertices
  // (Note: The vertex number is one grater than its index in the array.)
  vector<Vertex *> vertices;
  for(int i = 0; i != 7; ++i) vertices.push_back(new Vertex(i + 1));

  // create edges (implicitly encoded in vertices' list of adjacent vertices)
  // each vertex has a list of outgoing edges, which contain the vertex
  // at the other end of the edge (adjacent vertex), and the cost of the edge
  vertices[0]->adj.push_back(OutgoingEdge(vertices[1], 2));
  vertices[0]->adj.push_back(OutgoingEdge(vertices[3], 1));
  vertices[1]->adj.push_back(OutgoingEdge(vertices[3], 3));
  vertices[1]->adj.push_back(OutgoingEdge(vertices[4], 10));
  vertices[2]->adj.push_back(OutgoingEdge(vertices[0], 4));
  vertices[2]->adj.push_back(OutgoingEdge(vertices[5], 5));
  vertices[3]->adj.push_back(OutgoingEdge(vertices[2], 2));
  vertices[3]->adj.push_back(OutgoingEdge(vertices[4], 2));
  vertices[3]->adj.push_back(OutgoingEdge(vertices[5], 8));
  vertices[3]->adj.push_back(OutgoingEdge(vertices[6], 4));
  vertices[4]->adj.push_back(OutgoingEdge(vertices[6], 6));
  vertices[6]->adj.push_back(OutgoingEdge(vertices[5], 1));

  return vertices;
}

bool single_source_shortest_path_test(int test)
{
  vector<Vertex *> vertices = graph_9_20();

  if(test == 1)
  {
    dijkstra(vertices, vertices[0]);
    if(vertices[0]->path != NULL) return false;
    if(vertices[1]->path->key != 1) return false;
    if(vertices[2]->path->key != 4) return false;
    if(vertices[3]->path->key != 1) return false;
    if(vertices[4]->path->key != 4) return false;
    if(vertices[5]->path->key != 7) return false;
    if(vertices[6]->path->key != 4) return false;
  }
  else if(test == 2)
  {
    dijkstra(vertices, vertices[1]);
    if(vertices[0]->path->key != 3) return false;
    if(vertices[1]->path != NULL) return false;
    if(vertices[2]->path->key != 4) return false;
    if(vertices[3]->path->key != 2) return false;
    if(vertices[4]->path->key != 4) return false;
    if(vertices[5]->path->key != 7) return false;
    if(vertices[6]->path->key != 4) return false;
  }
  else if(test == 3)
  {
    dijkstra(vertices, vertices[2]);
    if(vertices[0]->path->key != 3) return false;
    if(vertices[1]->path->key != 1) return false;
    if(vertices[2]->path != NULL) return false;
    if(vertices[3]->path->key != 1) return false;
    if(vertices[4]->path->key != 4) return false;
    if(vertices[5]->path->key != 3) return false;
    if(vertices[6]->path->key != 4) return false;
  }
  else if(test == 4)
  {
    dijkstra(vertices, vertices[3]);
    if(vertices[0]->path->key != 3) return false;
    if(vertices[1]->path->key != 1) return false;
    if(vertices[2]->path->key != 4) return false;
    if(vertices[3]->path != NULL) return false;
    if(vertices[4]->path->key != 4) return false;
    if(vertices[5]->path->key != 7) return false;
    if(vertices[6]->path->key != 4) return false;
  }
  else if(test == 5)
  {
    dijkstra(vertices, vertices[4]);
    print_path(vertices[1]);
    if(vertices[0]->path != NULL) return false;
    if(vertices[1]->path != NULL) return false;
    if(vertices[2]->path != NULL) return false;
    if(vertices[3]->path != NULL) return false;
    if(vertices[4]->path != NULL) return false;
    if(vertices[5]->path->key != 7) return false;
    if(vertices[6]->path->key != 5) return false;
  }
  else if(test == 6)
  {
    dijkstra(vertices, vertices[5]);
    if(vertices[0]->path != NULL) return false;
    if(vertices[1]->path != NULL) return false;
    if(vertices[2]->path != NULL) return false;
    if(vertices[3]->path != NULL) return false;
    if(vertices[4]->path != NULL) return false;
    if(vertices[5]->path != NULL) return false;
    if(vertices[6]->path != NULL) return false;
  }
  else if(test == 7)
  {
    dijkstra(vertices, vertices[6]);
    if(vertices[0]->path != NULL) return false;
    if(vertices[1]->path != NULL) return false;
    if(vertices[2]->path != NULL) return false;
    if(vertices[3]->path != NULL) return false;
    if(vertices[4]->path != NULL) return false;
    if(vertices[5]->path->key != 7) return false;
    if(vertices[6]->path != NULL) return false;
  }
  else exit(1);

  return true;
}

int main(int argc, char ** argv)
{
  if(argc != 2)
  {cerr << "usage: " << argv[0] << " test_number" << endl; exit(1);}

  //vector<Vertex *> vertices = graph_9_20();

  //dijkstra(vertices, vertices[2]); // this is vertex 3 in figure 9.20

  //print_path(vertices[6]); // this is vertex 7 in figure 9.20

  //for(int j = 0; j != (int)vertices.size(); j++)
  //{
  //  vector<Vertex *> vertices = graph_9_20();
  //  dijkstra(vertices, vertices[j]);
  //  for(int i = 0; i != (int)vertices.size(); i++)
  //    if(vertices[i]->path == NULL) cout << "  ";
  //    else cout << vertices[i]->path->key << " ";
  //  cout << endl;
  //}

  //cout << endl;

  int test = atoi(argv[1]);

  ofstream out("result.txt");

  if(test == 1)
  {
    if(single_source_shortest_path_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 2)
  {
    if(single_source_shortest_path_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 3)
  {
    if(single_source_shortest_path_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 4)
  {
    if(single_source_shortest_path_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 5)
  {
    if(single_source_shortest_path_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 6)
  {
    if(single_source_shortest_path_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  if(test == 7)
  {
    if(single_source_shortest_path_test(test)) out << test << endl;
    else out << 0 << endl;
  }

  return 0;
}
