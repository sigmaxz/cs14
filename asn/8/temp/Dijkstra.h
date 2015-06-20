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
    if(!(vertices[i]->known))
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
    if(v == NULL) 
    {
      break;
    }
    v->known = true;
    
    for( adj_iter q = v->adj.begin() ; q != v->adj.end(); q++)
    {
      if( !(q->vertex->known))
      {
        if(v->dist + q->cost < q->vertex->dist )
        {
          q->vertex->dist = v->dist + q->cost;
          q->vertex->path = v;
        }
      }
    }
  }

}

#endif
