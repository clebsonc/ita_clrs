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


void Graph::depth_first_search(){
  for(umap::iterator it = adj_list.begin(); it!=adj_list.end(); it++){
    it->second.first.setColor(Color::WHITE);
    it->second.first.setPredecessor("");
  }
  int time = 0;
  for(umap::iterator it = adj_list.begin(); it!=adj_list.end(); it++){
    if(it->second.first.getColor() == Color::WHITE){
      depth_first_search_visit(it, time);
    }
  }
}


void Graph::depth_first_search_visit(umap::iterator & it, int & time){
  time++;
  it->second.first.setDiscoveredTime(time);
  it->second.first.setColor(Color::GRAY);
  for(std::string s : it->second.second){
    umap::iterator v = adj_list.find(s);
    if(v->second.first.getColor() == Color::WHITE){
      v->second.first.setPredecessor(it->first);
      depth_first_search_visit(v, time);
    }
  }
  time++;
  it->second.first.setFinishedTime(time);
}


std::list<std::string> Graph::depth_first_search_list(){
  for(umap::iterator it = adj_list.begin(); it!=adj_list.end(); it++){
    it->second.first.setColor(Color::WHITE);
    it->second.first.setPredecessor("");
  }
  int time = 0;
  std::list<std::string> list;
  for(umap::iterator it = adj_list.begin(); it!=adj_list.end(); it++){
    if(it->second.first.getColor() == Color::WHITE){
      depth_first_search_visit_list(it, list, time);
    }
  }
  return list;
}


void Graph::depth_first_search_visit_list(umap::iterator & it, 
  std::list<std::string> & list,  int & time){
  time++;
  it->second.first.setDiscoveredTime(time);
  it->second.first.setColor(Color::GRAY);
  for(std::string s : it->second.second){
    umap::iterator v = adj_list.find(s);
    if(v->second.first.getColor() == Color::WHITE){
      v->second.first.setPredecessor(it->first);
      depth_first_search_visit_list(v, list, time);
    }
  }
  time++;
  it->second.first.setFinishedTime(time);
  list.emplace_front(it->first);
}

std::list<GraphNode> Graph::topological_sort(){
  for(umap::iterator it = adj_list.begin(); it != adj_list.end(); it++){
    it->second.first.setColor(Color::WHITE);
    it->second.first.setPredecessor("");
  }
  int time=0;
  std::list<GraphNode> list;
  for(umap::iterator it = adj_list.begin(); it != adj_list.end(); it++){
    if(it->second.first.getColor() == Color::WHITE){
      topological_sort_visit(it, list, time);
    }
  }
  return list;
}


void Graph::topological_sort_visit(umap::iterator & it, 
  std::list<GraphNode> & list, int & time){
  time = time + 1;
  it->second.first.setColor(Color::GRAY);
  it->second.first.setDiscoveredTime(time);
  for(std::string s : it->second.second){
    umap::iterator v = adj_list.find(s);
    if(v->second.first.getColor() == Color::WHITE){
      v->second.first.setPredecessor(it->first);
      topological_sort_visit(v, list, time);
    }
  }
  time++;
  it->second.first.setFinishedTime(time);
  list.emplace_front(it->second.first);
  it->second.first.setColor(Color::BLACK);
}

void Graph::print_path(std::string source, std::string destine) const{
  if(source == destine)
    std::cout << source << " - ";
  else{
    umap::const_iterator it = adj_list.find(destine);
    if(it!=adj_list.end()){ // element exists
      std::string predecessor = it->second.first.getPredecessor();
      if(predecessor == ""){
        std::cout << "There's no path from source to destine." <<std::endl;
      } else{
        print_path(source, predecessor);
        std::cout << destine << " - ";
      }
    }
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


Graph Graph::transpose(){
  Graph gt;
  for(umap::iterator it = adj_list.begin(); it!=adj_list.end(); it++){
    gt.insertNode(it->first);
  }
  for(umap::iterator it = adj_list.begin(); it!= adj_list.end(); it++){
    for(std::string s : it->second.second){
      gt.insertEdge(s, it->first);
    }
  }
  return gt;
}


void Graph::print_strongly_connected_component(){
  std::list<std::string> preference = depth_first_search_list();
  Graph gt = this->transpose();
  gt.depth_first_search(preference);
}


void Graph::depth_first_search(std::list<std::string> & preference){
  for(umap::iterator it = adj_list.begin(); it!= adj_list.end(); it++){
    it->second.first.setColor(Color::WHITE);
    it->second.first.setPredecessor("");
  }
  int time = 0;
  int count = 1;
  while(!preference.empty()){
    umap::iterator it = adj_list.find(preference.front());
    preference.pop_front();
    std::cout << "Component " << count << ": ";
    if(it->second.first.getColor() == Color::WHITE){
      depth_first_search_visit(it, preference, time);
    }
    std::cout << "\n";
    count++;
  }
}


void Graph::depth_first_search_visit(umap::iterator & it, 
      std::list<std::string> & preference, int & time){
  time++;
  it->second.first.setColor(Color::GRAY);
  it->second.first.setDiscoveredTime(time);
  for(std::string s : it->second.second){
    preference.remove(s);
    umap::iterator v = adj_list.find(s);
    if(v->second.first.getColor() == Color::WHITE){
      v->second.first.setPredecessor(it->first);
      depth_first_search_visit(v, preference, time);
    }
  }
  std::cout << it->first << "_";
  time++;
  it->second.first.setFinishedTime(time);
  it->second.first.setColor(Color::BLACK);
}

