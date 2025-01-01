#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

bool cycleDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adj){
    visited[node] = true;
    dfsvisited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = cycleDfs(neighbour, visited, dfsvisited, adj);

            if(cycleDetected){
                return true;
            }
        }

        else if(dfsvisited[neighbour]){
            return true;
        }
    }

    dfsvisited[node] = false;
    return false;
}

int detectCycle(int n, vector<pair<int, int>> &edges){
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bool cycleFound = cycleDfs(i, visited, dfsVisited, adj);

            if(cycleFound){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n; // number of nodes in the graph
    cin >> n;

    vector<pair<int, int>> edges; // pairs of nodes representing edges in the graph

    // input the number of edges
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
    }

    // call the detectCycle function
    if (detectCycle(n, edges)) {
        cout << "Cycle found in the graph" << endl;
    } else {
        cout << "No cycle in the graph" << endl;
    }

    return 0;
}