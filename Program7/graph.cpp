/**
 * Author: Mohammed Ali
 * Version: 12132019
 * 
 * This program implements a graph data structure and creates 
 * a big data graph. It will tell you if it is possible to go from
 * one airport to another.
 * 
 * READ ME
 * Be sure to use the 3 letter airport code in the program.
 * Be sure to also have the RoutesModified file in folder as it will only work with that file.
 * 
 * This file implements the .h file which consists of the methods and class infroamtion
 * 
 */

#include "graph.h"

Vertex::Vertex(std::string location) {
    this->location_name = location;
}

// Load destinations of unique trips 
std::vector<std::pair<std::string,std::string> > Graph::load(std::string input) {
    std::ifstream input_file;
    input_file.open(input);

    std::string line;
    int location_count = 0;
    while (!input_file.eof()) {
        input_file >> line;
        std::vector<std::string> parts = this->split(line, ',');
        std::string start = parts[0];
        std::string end = parts[1];
        std::pair<std::string, std::string> leg;
        leg.first = start;
        leg.second = end;
        destinations.push_back(leg);
    }
    return destinations;
}

// Ensures no comma is entered into graph and is used to above function
std::vector<std::string> Graph::split(const std::string& s, char delim) {
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

//function that searches for inputs in graph
bool Graph::search(std::string start, std::string end) {
    for (int i = 0; i < destinations.size(); i++) {
        std::pair<std::string, std::string> curr = destinations[i];
        if (curr.first == start && curr.second == end) {
            return true;
        }
    }
    return false;
}