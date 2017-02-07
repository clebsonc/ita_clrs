#ifndef ADJACENCY_LIST_HPP_
#define ADJACENCY_LIST_HPP_

#include <unordered_map>
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <string>

#include "graph_node.hpp"
#include "graph_hash.hpp"
#include "color.hpp"

class Graph{
  private:
    /**
    * Alias for unordered_map, this is the adjacency list representation of the
    * graph.
    * The use of the hash is to boost up performance, since the lookup on the
    * hash table has an average complexity of O(1);
    */
    using umap = std::unordered_map<std::string,
      std::pair<GraphNode, std::vector<std::string> > >;

    umap adj_list;

  public:
    /**
    * Default constructor
    */
    Graph();
    
    /**
    * Insert a new node into the graph
    * node_name: A string representing the name of the graph node
    */
    void insertNode(const std::string & node_name);

    /**
    * Insert an edge between node1 and node2. The node1 and node2 must be
    * already inserted into the graph.
    */
    void insertEdge(const std::string & node1, const std::string & node2);
  
    /**
    * Performs a breadth first search on the graph.
    * source: the starting node in which the search is to be performed
    */
    void breadth_first_search(std::string source);


    /**
    * Performs a depth first search in the graph.
    */
    void depth_first_search();

    /**
    * Performs a depth first search in the graph considering the start node as
    * the nodes in the list. As the neighbors of a given node are visited, its
    * reference in the list is removed.
    */
    void depth_first_search(std::list<std::string> & preference);
    
    /**
    * Visit each neighbor of a given node in the graph, considering the
    * preference list. As the neighbors are visited, its reference is removed
    * from the given list.
    */
    void depth_first_search_visit(umap::iterator & it, 
      std::list<std::string> & preference, int & time);
    
    /**
    * Visit each neighbor of a given node in the graph considering the 
    * hash table and default ordering of insertion.
    */
    void depth_first_search_visit(umap::iterator & it, int & time);
    
    /**
    * Perform a depth first search, but returns a list containing the
    * nodes names in decreasing ordering of finishing time.
    */
    std::list<std::string> depth_first_search_list();
    
    /**
    * Visit the neighbors of a given node, but return keeps track of the nodes
    * names considering its finishing time.
    */
    void depth_first_search_visit_list(umap::iterator & it, 
      std::list<std::string> & list, int & time);

    /**
    * Do a topological sort on the graph considering the ordering of insertiong
    * of the nodes in the hash table.
    */
    std::list<GraphNode> topological_sort();

    /**
    * Visit the neighbors of a given node, keeping track of the elements in the
    * topological sort scheme.
    */
    void topological_sort_visit(umap::iterator & it, 
      std::list<GraphNode> & list, int & time);

    /**
    * Print the path in the graph from a source node to a destine node.
    */
    void print_path(std::string source, std::string destine) const;
    
    /**
    * Print the graph adjacency list
    */
    void print_graph_adj_list() const;

    /**
    * Build and returns a transpose of the current graph. Thus, it reverses
    * all edges of the graph.
    */
    Graph transpose();
    
    /**
    * Print the existing connected components of the graph.
    */
    void print_strongly_connected_component();
};

#endif

