#include "graph_adj_list.hpp"

Graph::Graph(){
}

void Graph::insertNode(const std::string & name){
  NodeGraph ng(name);
  this->adj_list.emplace(name, ng);
}

void Graph::insertEdge(const std::string & s, const std::string & v,
  const int weight){
  std::unordered_map<std::string, NodeGraph>::iterator it1 = adj_list.find(s);
  std::unordered_map<std::string, NodeGraph>::iterator it2 = adj_list.find(v);
  if(it1 == adj_list.end()){
    insertNode(s);
    it1 = adj_list.find(s);
  }
  if(it2 == adj_list.end()){
    insertNode(v);
    it2 = adj_list.find(v);
  }
  it1->second.addNeighbor(v, weight);
}

void Graph::print_adjacency_list() const{
  using umap = std::unordered_map<std::string, NodeGraph>;
  for(umap::const_iterator it = adj_list.cbegin(); it != adj_list.end(); it++){
    std::cout << it->second.getNodeName() << "->";
    for(Edge e : it->second.getNeighbors()){
      std::cout << "(" << e.getDestine() << ", " << e.getWeight() << ") -- ";
    }
    std::cout << "\n";
  }
}

//TODO: void print_path(const std::string & s, const std::string & v) const;

//TODO: int getNumberOfPaths(const std::string & s, const std::string & v) const;

//TODO: void Graph::breadth_first_search(const std::string & source){

void read_graph(Graph & g){
  int n=0;
  std::cin >> n;
  std::string s;
  for(int i = 0; i < n; i++){
    std::cin >> s;
    g.insertNode(s);
  }
  std::cin >> n;
  for(int i = 0; i < n; i++){
    std::cin >> s;
    std::size_t found = s.find(",");
    if(found != std::string::npos){
      g.insertEdge(s.substr(0, found), s.substr(found+1));
    }
  }
}
