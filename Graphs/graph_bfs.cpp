#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// (0 based indexing and cant handle disconnected graphs)
vector<int> bfs(vector<int> adj[],int n){
    int vis[n] = {0}; // Visited Array 
    vis[0] = 1;
    queue<int> q;
    q.push(0);

    vector<int> bfs;

    while (!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);  

        for (auto it: adj[node]){   
            if(!vis[it]){   // Check if already visited or not
                vis[it] = 1;
                q.push(it);
            }
        }
        
    }
    return bfs;
}

void printAdjList(const vector<int> adj[], int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> adj[n+1];
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    printAdjList(adj,n);

    vector<int> bfs_result = bfs(adj,n);

    for(auto it: bfs_result){
        cout << it << " ";
    }
    return 0;
}