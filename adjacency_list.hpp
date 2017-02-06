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
    using umap = std::unordered_map<std::string,
      std::pair<GraphNode, std::vector<std::string> > >;

    umap adj_list;

  public:

    Graph();

    void insertNode(const std::string & node_name);

    void insertEdge(const std::string & node1, const std::string & node2);

    void breadth_first_search(std::string source);

    void depth_first_search();

    void depth_first_search_visit(umap::iterator & it, int & time);

    void print_path(std::string source, std::string destine) const;
    
    void print_graph_adj_list() const;

};

#endif

