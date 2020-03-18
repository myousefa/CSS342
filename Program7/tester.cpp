#include "graph.h"

Vertex::Vertex(std::string location) {
    this->location_name = location;
}


void Graph::load(std::string input) {
    std::ifstream input_file;
    input_file.open(input);

    std::string line;
    while (!input_file.eof()) {
        input_file >> line;
        std::vector<std::string> parts = this->split(line, ',');
        std::string start = parts[0];
        std::string end = parts[1];
        std::cout << start << " ------> " << end << std::endl;
    }
}
