//
// Created by Haonan on 12/5/2022.
//

#ifndef CFG_GRAPH_H
#define CFG_GRAPH_H

#include <vector>

class Graph {
    unsigned int num_nodes, num_edges;
    std::vector<bool> vis;
    std::vector<unsigned int> head, nxt, to;

public:
    Graph(const unsigned int, const unsigned int);
    Graph();
    void add_edge(const unsigned int, const unsigned int);
    bool find_edge(const unsigned int, const unsigned int);

};


#endif //CFG_GRAPH_H
