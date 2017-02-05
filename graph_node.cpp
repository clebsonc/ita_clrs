#include "graph_node.hpp"


GraphNode::GraphNode(){
  this->name = "";
  this->color = Color::WHITE;
  this->discovered = INT_MAX;
  this->finished = INT_MAX;
  this->predecessor = "";
}


GraphNode::GraphNode(std::string name){
  this->name = name;
  this->color = Color::WHITE;
  this->discovered = INT_MAX;
  this->finished = INT_MAX;
  this->predecessor = "";
}


std::string GraphNode::getName() const{
  return this->name;
}


Color GraphNode::getColor() const{
  return this->color;
}


int GraphNode::getDiscoveredTime() const{
  return this->discovered;
}


int GraphNode::getFinishedTime() const{
  return this->finished;
}


std::string GraphNode::getPredecessor() const{
    return this->predecessor;
}


void GraphNode::setName(std::string name){
  this->name = name;
}

void GraphNode::setColor(Color c){
  this->color = c;
}

void GraphNode::setDiscoveredTime(int time){
  this->discovered = time;
}

void GraphNode::setFinishedTime(int time){
  this->finished = time;
}

void GraphNode::setPredecessor(std::string p){
  this->predecessor = p;
}

bool GraphNode::operator==(const GraphNode & node) const{
  if(this->name == node.getName())
    return true;
  return false;
}

