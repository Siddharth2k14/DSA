#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj){
    vis[node] = true;
    for(auto neighbour : adj[node]){
        if(!vis[neighbour]){
            dfs(neighbour, vis, st, adj);
        }
    }

    st.push(node);
}

void newDfs(int top, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose){
    vis[top] = true;
    for(auto neighbour : transpose[top]){
        if(!vis[neighbour]){
            newDfs(neighbour, vis, transpose);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &edges){
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //Topological Sort
    stack<int> st;
    unordered_map<int, bool> vis;
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, vis, st, adj);
        }
    }

    //Transpose
    unordered_map<int, list<int>> transpose;
    for(int i = 0; i < V; i++){
        for(auto neighbour : adj[i]){
            transpose[neighbour].push_back(i);
        }
    }

    //Dfs call using above sequence
    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();

        if(!vis[top]){
            count++;
            newDfs(top, vis, transpose);
        }
    }

    return count;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> edges;
    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cout << "Enter edge " << i+1 << ": ";
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int result = kosaraju(V, edges);
    cout << "The number of strongly connected components is: " << result << endl;

    return 0;
}