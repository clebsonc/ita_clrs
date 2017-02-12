#include "node_graph.hpp"

NodeGraph::NodeGraph(const std::string s){
  this->nodeName = s;
  this->discovered = 0;
  this->finished = INT_MAX;
}


std::string NodeGraph::getNodeName() const{
  return this->nodeName;
}


std::list<Edge> NodeGraph::getNeighbors() const{
  return this->neighbors;
}


int NodeGraph::getDiscovered() const{
  return this->discovered;
}


int NodeGraph::getFinished() const{
  return this->finished;
}


Color NodeGraph::getColor() const{
  return this->color;
}


std::set<std::string> NodeGraph::getPredecessors() const{
  return this->predecessors;
}


void NodeGraph::setNodeName(const std::string & name){
  this->nodeName = name;
}


void NodeGraph::setNeighbors(std::list<Edge> neighbors){
  this->neighbors = neighbors;
}


void NodeGraph::setDiscovered(const int & discovered){
  this->discovered = discovered;
}


void NodeGraph::setFinished(const int & finished){
  this->finished = finished;
}


void NodeGraph::setColor(const Color & color){
  this->color = color;
}


void NodeGraph::addNeighbor(const std::string & d, const int & w){
  Edge e(this->nodeName, d, w);
  this->neighbors.emplace_back(e);
}

void NodeGraph::addPredecessor(const std::string & pred){
  this->predecessors.emplace(pred);
}



std::ostream & operator<<(std::ostream & os, const NodeGraph & ng){
  std::string nb = "";
  for(const Edge & e : ng.getNeighbors()){
    nb += "\t" + e.getDestine() +  "\n";
  }

  std::string pd = "";
  for(std::string s: ng.getPredecessors())
    pd += s + " - ";

  os << "Node Name: " << ng.getNodeName() << 
        "\nNeighbors: \n" << nb << 
        "\nPredecessors: " << pd <<
        "\nDiscovered: " << ng.getDiscovered() << 
        "\nFinished: " << ng.getFinished() << 
        "\nColor: " << (ng.getColor() == Color::kWhite ? "WHITE" : 
                        (ng.getColor() == Color::kGray ? "GRAY" : "BLACK"));

  return os;
}

void NodeGraph::clearPredecessor(){
  this->predecessors.clear();
}


/*
#include <iostream>
int main(){
  NodeGraph a("abelha");
  a.addNeighbor("mel", 20);
  a.addPredecessor("flor");
  a.setDiscovered(1);
  a.setFinished(25);
  a.setColor(Color::kBlack);

  std::cout << a << std::endl;

  return 0;
}*/
