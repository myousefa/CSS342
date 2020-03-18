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
 * TO RUN --> run both main.cpp and graph.cpp into terminal
 */

#include "graph.h"

int main() {
    //load file + create graph
    Graph g;
    g.load("ModifiedRoutes.csv");

    //get user input + store into variable
    std::cout << "What airport are you at right now? " << std::endl;    
    std::string currentLoc = "";
    std::cin >> currentLoc;
    std::cout << "What airport do you desire to go to? I will tell you if it is possible. " << std::endl;
    std::string endLoc = "";
    std::cin >> endLoc;

    //search graph for desired airports
    bool found = g.search(currentLoc, endLoc);
    if(found == true){
        std::cout << "Yes it is possible \n";
    }
    else { std:: cout << "No routes available\n"; }

    return 0;
}