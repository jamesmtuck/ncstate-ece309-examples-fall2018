#ifndef GRAPH_H
#define GRAPH_H

#include "List.h"

class Graph {
protected:
  int numNodes;

public:
  Graph(int n) : numNodes(n){};
  virtual void addEdge(int, int) = 0;

  virtual bool isAdjacent(int, int) = 0;
};

class SparseGraph : public Graph {
protected:
  class Node {
  public:
    List edge;
  };
  Node *nodes;

public:
  using adjacency_iterator = List::iterator;

  SparseGraph(int n);
  void addEdge(int, int) override;
  bool isAdjacent(int, int) override;

  adjacency_iterator getAdjacencyList(int node) {
    return nodes[node].edge.begin();
  }
};

class DenseGraph : public Graph {
  bool *edges;

public:
  DenseGraph(int n);
  void addEdge(int, int) override;
  bool isAdjacent(int, int) override;
};

#endif // GRAPH_H
