#include <iostream>
#include <new>
#include <cstdlib>
#include <exception>
#include <climits>

#include "adjacency_list.hpp"


int main(){
  Graph g;
  g.insertNode("r");
  g.insertNode("s");
  g.insertNode("t");
  g.insertNode("u");
  g.insertNode("v");
  g.insertNode("w");
  g.insertNode("x");
  g.insertNode("y");

  g.insertEdge("r", "s");
  g.insertEdge("s", "r");
  g.insertEdge("r", "v");
  g.insertEdge("v", "r");
  g.insertEdge("s", "w");
  g.insertEdge("w", "s");
  g.insertEdge("w", "t");
  g.insertEdge("t", "w");
  g.insertEdge("w", "x");
  g.insertEdge("x", "w");
  g.insertEdge("t", "x");
  g.insertEdge("x", "t");
  g.insertEdge("t", "u");
  g.insertEdge("u", "t");
  g.insertEdge("x", "u");
  g.insertEdge("u", "x");
  g.insertEdge("x", "y");
  g.insertEdge("y", "x");
  g.insertEdge("u", "y");
  g.insertEdge("y", "u");

  g.breadth_first_search("s");
  g.print_graph_adj_list();
  g.print_path_BFS("s", "y");
  std::cout << "\n";

  return 0;
}

