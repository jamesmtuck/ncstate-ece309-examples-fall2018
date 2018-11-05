#include "Graph.h"
#include "IntegerSet.h"
#include "Queue.h"
#include <stdio.h>

SparseGraph::SparseGraph(int n) : Graph(n) { nodes = new Node[numNodes]; }

void SparseGraph::addEdge(int v1, int v2) {
  nodes[v1].edge.append(v2);
  nodes[v2].edge.append(v1);
}

bool SparseGraph::isAdjacent(int v1, int v2) {
  List::iterator it = nodes[v1].edge.begin();
  while (!it.end()) {
    if (it.getItem() == v2) {
      return true;
    }
    it.increment();
  }
  return false;
}

DenseGraph::DenseGraph(int n) : Graph(n) {
  edges = new bool[numNodes * numNodes];
  for (int i = 0; i < numNodes * numNodes; i++)
    edges[i] = false;
}
void DenseGraph::addEdge(int v1, int v2) {
  edges[v1 * numNodes + v2] = true;
  edges[v2 * numNodes + v1] = true;
}

bool DenseGraph::isAdjacent(int v1, int v2) {
  return edges[v1 * numNodes + v2];
}

bool doesPathExist(Graph &g, int *path, int length) {
  for (int i = 0; i < length - 1; i++) {
    if (!g.isAdjacent(path[i], path[i + 1]))
      return false;
  }
  return true;
}

void visit(int node) { printf("%d ", node); }

void BreadthFirstSearch(SparseGraph &graph, int start) {
  IntegerSetHT discovered(1000);
  Queue frontier;
  frontier.push(start);
  discovered.insert(start);
  while (!frontier.empty()) {
    int node = frontier.peek();
    visit(node);
    SparseGraph::adjacency_iterator it = graph.getAdjacencyList(node);
    while (!it.end()) {
      int j = it.getItem();
      if (!discovered.search(j)) {
        frontier.push(j);
        discovered.insert(j);
      }
      it.increment();
    }
    frontier.pop();
  }
}

int main() {

  SparseGraph g(14);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);

  g.addEdge(1, 4);
  g.addEdge(3, 5);
  g.addEdge(2, 6);
  g.addEdge(3, 6);
  g.addEdge(2, 7);
  g.addEdge(1, 8);
  g.addEdge(7, 8);
  g.addEdge(1, 9);
  g.addEdge(4, 10);
  g.addEdge(6, 11);
  g.addEdge(7, 12);
  g.addEdge(8, 13);

  /*  int path[3] = {0, 1, 9};

    if (doesPathExist(g, path, 3))
      printf("Exists!\n");*/

  printf("BFS(0)=");
  BreadthFirstSearch(g, 0);
  printf("\nBFS(13)=");

  BreadthFirstSearch(g, 13);

  return 0;
}
