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
 * This is the .h file that has all the methods and information for other files
 * 
 */

#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

// Vertex is the node or the airport
class Vertex {
public:
    Vertex(std::string);

    // location_name to different nodes
    std::vector< std::pair<std::string,std::string> > legs;

    std::string location_name;
};

class Graph {
public:
    std::vector< std::pair<std::string, std::string> > load(std::string);
    std::vector<std::string> split(const std::string& s, char delim);
    std::vector< std::pair<std::string,std::string> > destinations;

    bool search(std::string, std::string);
};
#endif