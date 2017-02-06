#include "adjacency_list.hpp"



Graph::Graph(){
}

void Graph::insertNode(const std::string & node_name){
  umap::iterator it = adj_list.find(node_name);
  if(it == adj_list.end()){
    adj_list.emplace(node_name, 
        std::pair<GraphNode, std::vector<std::string>>(GraphNode(node_name),
          std::vector<std::string>{}));
  }
  else{
    std::cout << "The Node already exists in the graph." << std::endl;
  }
}


void Graph::insertEdge(const std::string & node1, const std::string & node2){
  umap::iterator it1;
  umap::iterator it2;
  it1 = adj_list.find(node1);
  it2 = adj_list.find(node2);
  if(it1 != adj_list.end() && it2 != adj_list.end()){ // element was found
    it1->second.second.emplace_back(it2->second.first.getName());
  } else {
    std::cout << "One of the nodes doesn't exist int the adjacency list" << std::endl;
  }
}


void Graph::print_graph_adj_list() const{
  for(auto & node: adj_list){
    std::cout << node.second.first.getName() << " -> ";
    for(auto neighbors : node.second.second){
      std::cout << neighbors << " -- ";
    }
    std::cout << "\n";
  }
}


void Graph::breadth_first_search(std::string source){
  umap::iterator it = adj_list.find(source);
  if(it==adj_list.end()){
    std::cout << "Source doesn't exist" << std::endl;
    return;
  } 

  for(umap::iterator i = adj_list.begin(); i != adj_list.end(); i++){
    i->second.first.setColor(Color::WHITE);
    i->second.first.setDiscoveredTime(INT_MAX);
    i->second.first.setPredecessor(""); 
  }
  it->second.first.setColor(Color::GRAY);
  it->second.first.setDiscoveredTime(0);
  std::queue<umap::iterator> q;
  q.emplace(it);
  while(!q.empty()){
    it = q.front();
    q.pop();
      for(std::string n : it->second.second){
        umap::iterator v = adj_list.find(n);
        if(v!=adj_list.end() && v->second.first.getColor() == Color::WHITE){
          v->second.first.setPredecessor(it->first);
          v->second.first.setColor(Color::GRAY);
          v->second.first.setDiscoveredTime(it->second.first.
              getDiscoveredTime()+1);
          q.emplace(v);
        }
      }
      it->second.first.setColor(Color::BLACK);
  }
}


void Graph::print_path_BFS(std::string source, std::string destine){
  if(source == destine)
    std::cout << source << " - ";
  else{
    umap::iterator it = adj_list.find(destine);
    if(it!=adj_list.end()){ // element exists
      std::string predecessor = it->second.first.getPredecessor();
      if(predecessor == ""){
        std::cout << "There's no path from source to destine." <<std::endl;
      } else{
        print_path_BFS(source, predecessor);
        std::cout << destine << " - ";
      }
    }
  }
}

