#include <iostream>
#include <new>
#include <cstdlib>
#include <exception>
#include <climits>
#include <string>

#include "adjacency_list.hpp"


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

int main(){
  Graph g;
  read_graph(g);

  g.print_graph_adj_list();
  g.depth_first_search();
  std::string s, d;
  std::cin >> s;
  std::cin  >> d;
  g.print_path(s, d);
  std::cout << "\n";

  return 0;
}

