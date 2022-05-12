#include <iostream>
#include <chrono>
#include <ctime>

#include "./includes/misc/hash.h"
#include "./includes/ds/graph.h"
#include "includes/ds/edge.h"
#include "includes/misc/io.h"


int main() {

    std::vector<Edge> edges;
    HashTable<unsigned int> ht;
    read_edges(edges, "/Users/lanranli/Downloads/cfg_result");
    for (const auto &edge: edges) {
        ht.add(edge.u);
        ht.add(edge.v);
    }

    std::cout << "test: " << edges[0].u << ": " << ht.hash_value(edges[0].u) << "\n";
    Graph g(std::max(ht.size(), (unsigned) edges.size()));
    for (const auto &edge: edges) {
        g.add_edge(ht.hash_value(edge.u), ht.hash_value(edge.v));
    }

    std::cout << "======== test ========" << "\n";
    std::cout << "Edge(" << edges[0].u << "," << edges[0].v << ") is in the graph? ";

    unsigned u = ht.hash_value(edges[0].u);
    unsigned v = ht.hash_value(edges[0].v);
    std::cout << g.find_edge(u, v) << "\n";


    std::cout << "======== test for all edges (" << edges.size() << ") ========" << "\n";
    auto start = std::chrono::system_clock::now();

    for (const auto &edge: edges) {
        u = ht.hash_value(edge.u);
        v = ht.hash_value(edge.v);
        if (!g.find_edge(u, v)) {
            std::cout << "errors at: " << edge.u << "," << edge.v << "\n";
        }
    }


    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s"
              << std::endl;
}