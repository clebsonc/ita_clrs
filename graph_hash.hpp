#ifndef GRAPH_HASH_HPP_
#define GRAPH_HASH_HPP_

#include <functional>
#include "graph_node.hpp"

class GraphHash{
  public:
    std::size_t operator()(const GraphNode & gp) const{
      return std::hash<std::string>{}(gp.getName());
    }
};


#endif

