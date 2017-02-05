#include "adjacency_list.hpp"


Graph::Graph(){
}

void Graph::insertNode(const std::string & node_name){
  std::unordered_map<GraphNode, std::vector<std::string>, GraphHash>::iterator it;
  it = adj_list.find(node_name);
  if(it == adj_list.end()){
    adj_list.emplace(GraphNode(node_name), std::vector<std::string>{});
  }
  else{
    std::cout << "The Node already exists in the graph." << std::endl;
  }
}



void Graph::insertEdge(const GraphNode & node1, const GraphNode & node2){
  std::unordered_map<GraphNode, std::vector<std::string>, GraphHash>::iterator it1;
  std::unordered_map<GraphNode, std::vector<std::string>, GraphHash>::iterator it2;
  it1 = adj_list.find(node1);
  it2 = adj_list.find(node2);
  if(it1 != adj_list.end() && it2 != adj_list.end()){ // element was found
    it1->second.emplace_back(it2->first.getName());
  } else {
    std::cout << "One of the nodes doesn't exist int the adjacency list" << std::endl;
  }
}


void Graph::print_graph_adj_list() const{
  for(auto & node: adj_list){
    std::cout << node.first.getName() << " -> ";
    for(auto neighbors : node.second){
      std::cout << neighbors << " -- ";
    }
    std::cout << "\n";
  }
}

