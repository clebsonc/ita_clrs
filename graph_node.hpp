#ifndef GRAPH_NODE_HPP_
#define GRAPH_NODE_HPP_

#include <string>
#include <climits>
#include "color.hpp"


class GraphNode{
  private:
    std::string name;
    Color color;
    int discovered;
    int finished;
    std::string predecessor;

  public:
    // Constructors
    int test;
    GraphNode();
    GraphNode(std::string name);
    

    // Getters and Setters
    std::string getName() const;
    Color getColor() const;
    int getDiscoveredTime() const;
    int getFinishedTime() const;
    std::string getPredecessor() const;
    
    void setName(std::string name);
    void setColor(Color c);
    void setDiscoveredTime(int time);
    void setFinishedTime(int time);
    void setPredecessor(std::string p);

    // Overloading Operators
    /**
    * This overload is necessary to compare if two objects are the same.
    * Returns true case node equals this object, false otherwise
    */
    bool operator==(const GraphNode & node) const;

};

#endif
