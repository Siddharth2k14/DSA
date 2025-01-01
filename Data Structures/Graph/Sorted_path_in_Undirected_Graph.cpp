#include<bits/stdc++.h>
using namespace std;

void path(unordered_map<int, bool> &visited, unordered_map<int, bool> &parent, queue<int> &q, unordered_map<int, list<int>> &adj, int s){
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int front  = q.front();
        q.pop();
        for(auto neighbour : adj[front]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    
}

vector<int> shortPath(vector<pair<int, int>> &edges, int n, int m, int s, int t){
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> parent;
    queue<int> q;
    path(visited, parent, q, adj, s);

    vector<int> ans;
	int currentNode = t;
	ans.push_back(t);

	while(currentNode != s){
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

int main(){

   return 0;
}