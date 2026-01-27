#include <iostream>
#include <bits/stdc++.h>
using namespace std;


long long dijkstra(int n, const vector<vector<int>>& edges, int src, int dst) {
    vector<vector<pair<int, int>>> adj(n);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
    }

    const long long INF = LLONG_MAX / 4;
    vector<long long> dist(n, INF);
    dist[src] = 0;

    priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

    pq.push({0, src});
    while (!pq.empty()) {
        pair<long long, int> cur = pq.top();
        pq.pop();
        long long d = cur.first;
        int u = cur.second;

        if (d != dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            long long nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    return dist[dst] >= INF ? -1 : dist[dst];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Test case 1
    {
        int n = 5;
        vector<vector<int>> edges = {
            {0, 1, 2},
            {0, 2, 4},
            {1, 2, 1},
            {1, 3, 7},
            {2, 4, 3},
            {3, 4, 1},
            {2, 3, 2}
        };
        int src = 0, dst = 4;
        long long ans = dijkstra(n, edges, src, dst);
        cout << ans << '\n'; // Expected: 6
    }

    // Test case 2
    {
        int n = 4;
        vector<vector<int>> edges = {
            {0, 1, 5},
            {1, 2, 6},
            {0, 2, 20},
            {2, 3, 2}
        };
        int src = 0, dst = 3;
        long long ans = dijkstra(n, edges, src, dst);
        cout << ans << '\n'; // Expected: 13
    }

    return 0;
}