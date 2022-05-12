//
// Created by lanranli-mac on 12/5/2022.
//

#include "../includes/ds/edge.h"
#include "../includes/misc/io.h"
#include <string>
#include <fstream>
#include <vector>

void read_edges(std::vector<Edge>& edges, const std::string &filename) {
    std::ifstream input_file(filename);
    unsigned int u, v;
    while (input_file >> u >> v) {
        edges.emplace_back(u, v);
    }
}