#ifndef NODE_GRAPH_HPP__
#define NODE_GRAPH_HPP__

#include <string>
#include <list>
#include <set>
#include <cstdlib>
#include <climits>

#include "edge.hpp"
#include "color.hpp"

class NodeGraph{
  private:
    std::string nodeName;
    std::list<Edge> neighbors;
    std::set<std::string> predecessors;

    int discovered;
    int finished;
    
    Color color;

  public:
    // Constructor
    NodeGraph(const std::string s);
    
    // Gettters and Setters
    std::string getNodeName() const;
    std::list<Edge> getNeighbors() const;
    int getDiscovered() const;
    int getFinished() const;
    Color getColor() const;
    std::set<std::string> getPredecessors() const;
    
    void setNodeName(const std::string & name);
    void setNeighbors(std::list<Edge> neighbors);
    void setDiscovered(const int & discovered);
    void setFinished(const int & finished);
    void setColor(const Color & Color);
    void clearPredecessor();
    

    void addNeighbor(const std::string & d, const int & w);
    void addPredecessor(const std::string & pred);
};

#endif
