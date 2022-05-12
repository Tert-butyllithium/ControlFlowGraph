#include <iostream>


#include "./includes/misc/hash.h"
#include "./includes/ds/graph.h"
#include "includes/ds/edge.h"
#include "includes/misc/io.h"


int main() {

    std::vector<Edge> edges;
    HashTable<unsigned int> ht;
    read_edges(edges,"/Users/lanranli/Downloads/cfg_result");
    for(const auto& edge: edges){
        ht.add(edge.u);
        ht.add(edge.v);
    }

    std::cout<<"test: "<< edges[0].u << ": " << ht.hash_value(edges[0].u) << "\n";
}