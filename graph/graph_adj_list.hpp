#ifndef GRAPH_ADJ_LIST_HPP_
#define GRAPH_ADJ_LIST_HPP_

#include <unordered_map>
#include <queue>
#include <iostream>


#include "node_graph.hpp"




class Graph{
  private:
    std::unordered_map<std::string, NodeGraph> adj_list;

  public:
    // Constructor
    Graph();

    void insertNode(const std::string & name);

    void insertEdge(const std::string & s, const std::string & v, 
      const int weight=1);

    void print_adjacency_list() const;

    //TODO: void print_path(const std::string & s, const std::string & v) const;
 
    //TODO: int getNumberOfPaths(const std::string & s, const std::string & v) const;

    //TODO: void breadth_first_search(const std::string & souce);
};

#endif
