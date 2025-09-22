#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>>& mat){
    int n = mat.size(); 
    for (int i = 1; i < n; i++) {    
        for (int j = 1; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
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

// Adjacency matrix 
// Space complexity is O(N x N)

// int main(){
//     int n;  // Number of nodes
//     int m;  // Number of edges

//     cin >> n >> m;
//     vector<vector<int>> adj(n+1,vector<int>(n+1,0));
    
//     for (int i = 0; i < m; i++){
//         int row;
//         int column;
//         cin >> row >> column;
//         adj[row][column] = 1;
//         adj[column][row] = 1;     
//     }
//     printMatrix(adj);
    
// }

// Adjacency list
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
}