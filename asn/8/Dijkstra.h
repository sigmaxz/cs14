// Course: CS 14 Spring 2012
//
// First Name: Samuel
// Last Name: Villarreal
// UCR Username: svill017
// UCR Email Address: svill017@student.ucr.edu
//
// Lecture Section: 001
// Lab Section: 022
// TA: Krystof Litomisk
//
// Assignment: assignment 8
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//
// ===========================================================================
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <climits>      // provides: INT_MAX
#include <list>         // provides: list

#define INFTY INT_MAX

struct Vertex;          // must declare here because OutgoingEdge uses it

struct OutgoingEdge
{
  Vertex * vertex;
  int      cost;
  OutgoingEdge(Vertex * vertex, int cost) : vertex(vertex), cost(cost) {}
};

typedef std::list<OutgoingEdge>::iterator adj_iter; // used in dijkstra()

struct Vertex
{
  int                     key;
  bool                    known;
  int                     dist;
  std::list<OutgoingEdge> adj;
  Vertex *                path;
  Vertex(int key) : key(key), known(false), dist(INFTY), adj(), path(NULL) {}
};

void print_path(Vertex * v)
{
  if(v->path != NULL)
  {
    print_path(v->path);
    std::cout << " to ";
  }
  std::cout << v->key;
}

Vertex * smallest_unknown(const std::vector<Vertex *> & vertices)
{
  Vertex* temp = NULL;
  for (unsigned i = 0; i < vertices.size(); i++)
  {
    if(vertices[i]->known == false)
    {
      if(!temp) temp = vertices[i];
      if(temp->dist > vertices[i]->dist) temp = vertices[i];
    }
  }
  return temp;
  
}

void dijkstra(std::vector<Vertex *> & vertices, Vertex * s)
{
  for (unsigned i = 0; i < vertices.size(); i++)
  {
    vertices[i]->dist = INFTY;
    vertices[i]->known = false;
  }
  
  s->dist = 0;
  
  while(true)
  {
    Vertex* v = smallest_unknown(vertices);
    if(v == NULL || v->dist == INFTY) break;
    
    v->known = true;
    
    for( adj_iter w = v->adj.begin() ; w != v->adj.end(); w++)
    {
      if( !(w->vertex->known))
      {
        if(v->dist + w->cost < w->vertex->dist )
        {
          w->vertex->dist = v->dist + w->cost;
          w->vertex->path = v;
        }
      }
    }
  }

}

#endif
