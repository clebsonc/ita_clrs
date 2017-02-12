#include "edge.hpp"

Edge::Edge(){
}

Edge::Edge(const std::string & s, const std::string & d, const int weight){
  this->source = s;
  this->destine = d;
  this->weight = weight;
}

std::string Edge::getSource() const{
  return this->source;
}

std::string Edge::getDestine() const{
  return this->destine;
}

int Edge::getWeight() const{
  return this->weight;
}

void Edge::setSource(const std::string s){
  this->source = s;
}

void Edge::setDestine(const std::string d){
  this->destine = d;
}

void Edge::setWeight(const int w){
  this->weight = w;
}

std::ostream & operator<<(std::ostream & os, const Edge & e){
  os << e.getSource() << " " << e.getDestine() << " " << e.getWeight();
  return os;
}

