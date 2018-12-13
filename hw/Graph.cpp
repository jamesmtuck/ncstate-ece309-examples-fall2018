#include "Graph.h"
#include <algorithm>
#include <climits>
#include <stdio.h>

SparseGraph::SparseGraph(int n) : Graph(n) { nodes = new Node[numNodes]; }

void SparseGraph::addEdge(int v1, int v2) {
  nodes[v1].edge.append(v2);
  nodes[v2].edge.append(v1);
}

bool SparseGraph::isAdjacent(int v1, int v2) const {
  List::iterator it = nodes[v1].edge.begin();
  while (!it.end()) {
    if (it.getItem() == v2) {
      return true;
    }
    it.increment();
  }
  return false;
}

DirectedSparseGraph::DirectedSparseGraph(int n) : SparseGraph(n) {}
void DirectedSparseGraph::addEdge(int from, int to) {
  nodes[from].edge.append(to);
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

bool DenseGraph::isAdjacent(int v1, int v2) const {
  return edges[v1 * numNodes + v2];
}

void WeightedDenseGraph::addWeight(int from, int to, int weight) {
  weights[from * numNodes + to] = weight;
  weights[to * numNodes + from] = weight;
}

void WeightedDenseGraph::addEdge(int from, int to, int weight) {
  addEdge(from, to);
  addWeight(from, to, weight);
}

class node_helper {
public:
  node_helper() {
    distance = INT_MAX;
    pred = -1;
    node = 0;
    index = 0;
  }
  int node;
  int index;
  int distance;
  int pred;
};

class NodeHelperMinHeap {
private:
  node_helper **heapArray; // this is the maxheap
  int heapArraySize;       // size of the array
  int nextIndex;           // location of next free array entry

protected:
  void percolate_up(int);
  void percolate_down(int, int);

public:
  NodeHelperMinHeap(int size, node_helper *array) : heapArraySize(size) {
    heapArray = new node_helper *[size];

    for (int i = 0; i < size; i++)
      heapArray[i] = NULL;
    nextIndex = 0;

    for (int i = 0; i < size; i++) {
      array[i].index = nextIndex;
      heapArray[nextIndex] = &array[i];
      percolate_up(nextIndex);
      nextIndex++;
    }
  }

  void print() {
    for (int i = 0; i < nextIndex; i++) {
      printf("Node %d distance=%d ", heapArray[i]->node,
             heapArray[i]->distance);
    }
    printf("\n");
  }

  bool insert(int);
  void update(node_helper *);
  bool remove(node_helper *&); // remove the max value

  bool empty() { return nextIndex == 0; }
};

void NodeHelperMinHeap::percolate_up(int index) {
  while (index > 0) {
    int parent_index = (index - 1) / 2;
    if (heapArray[index]->distance < heapArray[parent_index]->distance) {
      std::swap(heapArray[index], heapArray[parent_index]);
      heapArray[index]->index = index;
      heapArray[parent_index]->index = parent_index;
      index = parent_index;
    } else
      return;
  }
}

void NodeHelperMinHeap::percolate_down(int index, int size) {
  int child_index = index * 2 + 1;
  int val = heapArray[index]->distance;
  while (child_index < size) {
    int max_val = val;
    int max_index = -1;
    for (int i = child_index; i < child_index + 2 && i < size; i++) {
      if (heapArray[i]->distance > max_val) {
        max_val = heapArray[i]->distance;
        max_index = i;
      }
    }
    if (max_val == val)
      return;

    std::swap(heapArray[index], heapArray[max_index]);
    heapArray[index]->index = index;
    heapArray[max_index]->index = max_index;
    index = max_index;
    child_index = index * 2 + 1;
  }
}

void NodeHelperMinHeap::update(node_helper *node) {
  if (node->index < nextIndex) {
    percolate_up(node->index);
  }
}

bool NodeHelperMinHeap::remove(node_helper *&val) {
  if (nextIndex > 0) {
    val = heapArray[0];
    heapArray[0] = heapArray[nextIndex - 1];
    nextIndex -= 1;
    percolate_down(0, nextIndex);
    return true;
  }
  return false;
}

node_helper *ShortestPath(Graph &g, int startV) {

  int numNodes = g.getNumNodes();
  node_helper *nodesH = new node_helper[numNodes];
  nodesH[startV].distance = 0;
  for (int i = 0; i < numNodes; i++)
    nodesH[i].node = i;

  NodeHelperMinHeap minheap(numNodes, nodesH);

  node_helper *next;

  while (minheap.remove(next)) {
    int min_distance = next->distance;
    int currentV = next->node;
    List adjList = g.getAdjacencyList(currentV);

    for (List::iterator lit = adjList.begin(); !lit.end(); lit.increment()) {
      int toNode = lit.getItem();
      if (g.getWeight(currentV, toNode) + min_distance <
          nodesH[toNode].distance) {
        nodesH[toNode].distance = g.getWeight(currentV, toNode) + min_distance;
        nodesH[toNode].pred = currentV;
        minheap.update(&nodesH[toNode]);
      }
    }
  }
  return nodesH;
}

int main() {

  WeightedDenseGraph wg(6);
  wg.addEdge(0, 1, 450);
  wg.addEdge(0, 3, 150);
  wg.addEdge(0, 2, 370);
  wg.addEdge(1, 3, 550);
  wg.addEdge(2, 4, 210);
  wg.addEdge(3, 4, 370);
  wg.addEdge(3, 5, 340);
  wg.addEdge(2, 5, 130);
  wg.addEdge(4, 5, 5);

  node_helper *path = ShortestPath(wg, 0);

  for (int i = 0; i < wg.getNumNodes(); i++) {
    printf("[%d] distance=%d pred=%d\n", path[i].node, path[i].distance,
           path[i].pred);
  }

  return 0;
}
