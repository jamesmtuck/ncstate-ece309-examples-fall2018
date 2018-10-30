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
  SparseGraph(int n);
  void addEdge(int, int) override;
  bool isAdjacent(int, int) override;
};

class DenseGraph : public Graph {
  bool *edges;

public:
  DenseGraph(int n);
  void addEdge(int, int) override;
  bool isAdjacent(int, int) override;
};

#endif // GRAPH_H
