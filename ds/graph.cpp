//
// Created by Haonan on 12/5/2022.
//

#include "../includes/ds/graph.h"

Graph::Graph(const unsigned int nodes) : num_nodes(nodes) {
    this->vis.resize(num_nodes + 1, false);
    this->head.resize(num_nodes + 1, 0);
    this->add_edge(0, 0);
}

void Graph::add_edge(const unsigned int u, const unsigned int v) {
    this->nxt.push_back(this->head[u]);
    this->head[u] = this->to.size();
    this->to.push_back(v);
}

bool Graph::find_edge(const unsigned int u, const unsigned int v) {
    for (unsigned int i = this->head[u]; i; i = this->nxt[i]) {
        if (this->to[i] == v) {
            return true;
        }
    }
    return false;
}