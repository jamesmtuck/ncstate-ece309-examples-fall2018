#ifndef GRAPH_H
#define GRAPH_H

#include "List.h"

class Graph {
protected:
  int numNodes;

public:
  Graph(int n) : numNodes(n){};
  virtual void addEdge(int, int) = 0;
  virtual bool isAdjacent(int, int) const = 0;

  virtual List getAdjacencyList(int) const = 0;
  virtual int getWeight(int, int) const { return 1; }
  int getNumNodes() const { return numNodes; }
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
  bool isAdjacent(int, int) const override;

  List getAdjacencyList(int node) const override { return nodes[node].edge; }
};

class DirectedSparseGraph : public SparseGraph {
public:
  DirectedSparseGraph(int n);
  void addEdge(int, int) override;
};

class DenseGraph : public Graph {
  bool *edges;

public:
  DenseGraph(int n);
  void addEdge(int, int) override;
  bool isAdjacent(int, int) const override;

  List getAdjacencyList(int node) const override {
    List ret;
    for (int i = 0; i < numNodes; i++) {
      if (isAdjacent(node, i)) {
        ret.append(i);
      }
    }
    return ret;
  }
};

class WeightedDenseGraph : public DenseGraph {
protected:
  int *weights;
  void addWeight(int from, int to, int weight);

private:
  void addEdge(int f, int t) override { DenseGraph::addEdge(f, t); }

public:
  WeightedDenseGraph(int n) : DenseGraph(n) {
    weights = new int[n * n];
    for (int i = 0; i < n * n; i++)
      weights[i] = 0;
  }

  void addEdge(int src, int dest, int weight);
  int getWeight(int src, int dest) const override {
    return weights[src * numNodes + dest];
  }
};

#endif // GRAPH_H
