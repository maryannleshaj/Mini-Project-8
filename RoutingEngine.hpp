#ifndef ROUTING_ENGINE_HPP
#define ROUTING_ENGINE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

struct Edge {
    string dest;
    int bandwidth;
};

class RoutingEngine {
private:
    //Adjacency list: Map a device name to a list of connected edges
    unordered_map<string, vector<Edge>> graph;

    //Recursive DFS helper
    bool dfs(string current, string target, int minBW, set<string>& visited, vector<string>& path) {
        visited.insert(current);
        path.push_back(current);

        if (current == target) return true;

        for (const auto& edge : graph[current]) {
            //only follow path if bandwidth is high enough and node isnt visited
            if (edge.bandwidth >= minBW && visited.find(edge.dest) == visited.end()) {
                if (dfs(edge.dest, target, minBW, visited, path)) return true;
            }
        }

        //backtrack if no path found
        path.pop_back();
        return false;
    }
public:
    void buildGraph(string filename) {
        ifstream file(filename);
        string src, dest;
        int bw;
        while (file >> src >> dest >> bw) {
            graph[src].push_back({dest, bw});
            graph[dest].push_back({src, bw}); //assuming bi directional network
        }
    }
    void findPath(string start, string end, int minBW) {
        set<string> visited;
        vector<string> path;
        
        cout << "Searching for path from " << start << " to " << end << " with min BW: " << minBW << "..." << endl;

        if (dfs(start, end, minBW, visited, path)) {
            cout << "Path found: ";
            for (size_t i = 0; i < path.size(); ++i) {
                cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
            }
            cout << endl;
        } else {
            cout << "No suitable path exists with " << minBW << " Mbps bandwidth." << endl;
        }
    }
};

#endif