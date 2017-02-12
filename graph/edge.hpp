#ifndef EDGE_HPP_
#define EDGE_HPP_

#include <string>
#include <ostream>

class Edge{
  private:
    std::string source;
    std::string destine;

    int weight;

  public:
    // constructors
    Edge();
    Edge(const std::string & s, const std::string & d, const int weight);
    
    // getters and setters
    std::string getSource() const;
    std::string getDestine() const;
    int getWeight() const;

    void setSource(const std::string s);
    void setDestine(const std::string d);
    void setWeight(const int w);

};

#endif

