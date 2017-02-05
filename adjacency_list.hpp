#ifndef ADJACENCY_LIST_HPP_
#define ADJACENCY_LIST_HPP_

#include <unordered_map>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

#include "graph_node.hpp"
#include "graph_hash.hpp"
#include "color.hpp"


class Graph{
  private:
    std::unordered_map<GraphNode, std::vector<std::string>, GraphHash> adj_list;

  public:
    Graph();

    void insertNode(const std::string & node_name);


    void insertEdge(const GraphNode & node1,
        const GraphNode & node2);

    void print_graph_adj_list() const;

};





#endif
