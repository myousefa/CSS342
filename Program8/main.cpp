/**
 * Author: Mohammed Ali
 * Version: 12122019
 * This program implements Dijkstra's Algorithm to find the 
 * fastest route from one airport to the other.
 * It also displays the amount of layovers it takes 
 * to get from the current airport to the other.
 * 
 * Be sure to run un c++ version 11: -std=c++11
 */

#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Graph
{
    unordered_map<string, const unordered_map<string, int>> vertices;
    
public:
    void add_vertex(string name, const unordered_map<string, int>& edges)
    {
        // Insert the connected nodes in unordered map
        vertices.insert(unordered_map<string, const unordered_map<string, int>>::value_type(name, edges));
    }
    
    vector<string> shortest_path(string start, string finish)
    {
        // Second arguments -> distances
        // Find the smallest distance in the already in closed list and push it in -> previous
        unordered_map<string, int> distances;
        unordered_map<string, string> previous;
        vector<string> nodes; // Open list
        vector<string> path; // Closed list
        
        auto comparator = [&] (string left, string right) { return distances[left] > distances[right]; };
        
        for (auto& vertex : vertices)
        {
            if (vertex.first == start)
            {
                distances[vertex.first] = 0;
            }
            else
            {
                distances[vertex.first] = numeric_limits<int>::max();
            }
            
            nodes.push_back(vertex.first);
            push_heap(begin(nodes), end(nodes), comparator);
        }
        
        while (!nodes.empty())
        {
            pop_heap(begin(nodes), end(nodes), comparator);
            string smallest = nodes.back();
            nodes.pop_back();

            
            if (smallest == finish)
            {
                while (previous.find(smallest) != end(previous))
                {
                    path.push_back(smallest);
                    smallest = previous[smallest];
                    std::cout << "Solution path given in backwards order: ";
                    for( std::vector<string>::const_iterator i = path.begin(); i != path.end(); ++i)
                        std::cout << *i << ' ';
                    std::cout << std::endl;
                }
                
                break;
            }
            
            if (distances[smallest] == numeric_limits<int>::max())
            {
                break;
            }
            
            for (auto& neighbor : vertices[smallest])
            {
                int alt = distances[smallest] + neighbor.second;
                if (alt < distances[neighbor.first])
                {
                    distances[neighbor.first] = alt;
                    previous[neighbor.first] = smallest;
                    make_heap(begin(nodes), end(nodes), comparator);
                }
            }
        }
        
        return path;
    }
};

int main()
{
    //Create graph data struct
    Graph g;
    //add vertecies into graph + distance
    g.add_vertex("LAX", {{"PAE", 986}});
    g.add_vertex("PAE", {{"LVS", 1245}});
    g.add_vertex("ORD", {{"SEA", 1721}, {"LAX", 1742}, {"JFK", 738}});
    g.add_vertex("SEA", {{"JFK", 2415}, {"MSP", 1395}});
    g.add_vertex("MSP", {{"JFK", 1026}, {"ORD", 334}, {"PIT", 724}});
    g.add_vertex("LVS", {{"JFK", 1742}, {"MSP", 920}});
    g.add_vertex("ATL", {{"PBI", 546}});
    g.add_vertex("JFK", {{"PBI", 1030}, {"PIT", 340}});
    
    //variables to track current airport and desired end airport
    string currentLocation = "LAX";
    string endLocation = "SEA";
    
    //Variale to keep count of amount of layovers
    int layoverCounter = 0;
    //Display in terminal current location and end location
    cout << "Current airport: " << currentLocation << endl;
    cout << "End airport: " << endLocation << endl;

    //For each loop that locates the shortest path in the graph from current airport to end airport
    for (string vertex : g.shortest_path(currentLocation, endLocation))
    {
        //print path + Layover information
        cout << "Solution path from goal : " << layoverCounter << " Layover : " << vertex << endl;
        //Each time it goes through for each loop and increments
        layoverCounter++;
    }
    //if layover counter is 0 it means it was unable to find any path to even get to the destination in the graph
    if(layoverCounter == 0){
        cout << "not possible" << endl;
    } else {
        //print current location as the for each loop does not print the start loc
        cout << "Solution path from goal : " << layoverCounter << " Layover : " << currentLocation << endl;
    }
    
    return 0;
}