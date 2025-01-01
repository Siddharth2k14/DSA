#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(int node, int timer, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, vector<vector<int>> &result, unordered_map<int, list<int>> &adj){
    vis[node] = true;
    disc[node] = low[node] = timer++;
    
    for(auto neighbour : adj[node]){
        if(neighbour == parent){
            continue;
        }

        if(!vis[neighbour]){
            dfs(neighbour, timer, node, disc, low, vis, result, adj);
            low[node] = min(low[node], low[neighbour]);

            if(low[neighbour] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }

        else{
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> Bridge(vector<vector<int>> &edges, int v, int e){
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v);
    int parent = -1;
    vector<int> low(v);
    unordered_map<int, bool> vis;

    vector<vector<int>> result;
    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, timer, parent, disc, low, vis, result, adj);
        }
    }

    return result;
}

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter the edges (u v): " << endl;
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> result = Bridge(edges, v, e);

    cout << "Bridges:" << endl;
    for (const auto& bridge : result) {
        cout << "(" << bridge[0] << ", " << bridge[1] << ")" << endl;
    }

    return 0;
}