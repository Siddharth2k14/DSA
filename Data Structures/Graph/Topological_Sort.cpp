#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj){
    visited[node] = true;

    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour, visited, s, adj);
        }
    }

    s.push(node);
}

vector<int> TopologicalSort(vector<vector<int>> &edges, int v, int e){
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    for(int i = 0; i < v; i++){
        if(!visited[i]){
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    cout << "Enter the edges: " << endl;
    for(int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> topoSortAns = TopologicalSort(edges, V, E);

    if(topoSortAns.size() == V) {
        cout << "Topological Sort: ";
        for(int i = 0; i < V; i++) {
            cout << topoSortAns[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Topological Sort is not possible as the graph contains a cycle." << endl;
    }

    return 0;
}