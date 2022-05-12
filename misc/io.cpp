//
// Created by lanranli-mac on 12/5/2022.
//

#include "../includes/ds/graph.h"
#include <string>
#include <fstream>

bool read_edges(Graph &g, const std::string filename) {
    std::ifstream input_file(filename);
    if(!input_file){
        return false;
    }
    unsigned u,v;

}