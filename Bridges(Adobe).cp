#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int parent, vector<int>& disc, vector<int>& low, vector<bool>& visited, vector<vector<int>>& adj, vector<pair<int, int>>& bridges, int& time) {
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, u, disc, low, visited, adj, bridges, time);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                bridges.push_back({min(u, v), max(u, v)});
            }
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

vector<pair<int, int>> findCriticalConnections(int n, vector<pair<int, int>>& connections) {
    vector<vector<int>> adj(n + 1);
    for (auto& connection : connections) {
        adj[connection.first].push_back(connection.second);
        adj[connection.second].push_back(connection.first);
    }

    vector<int> disc(n + 1, -1), low(n + 1, -1);
    vector<bool> visited(n + 1, false);
    vector<pair<int, int>> bridges;
    int time = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, -1, disc, low, visited, adj, bridges, time);
        }
    }

    sort(bridges.begin(), bridges.end());
    return bridges;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> connections(m);
    for (int i = 0; i < m; ++i) {
        cin >> connections[i].first >> connections[i].second;
    }

    vector<pair<int, int>> criticalConnections = findCriticalConnections(n, connections);

    for (auto& conn : criticalConnections) {
        cout << conn.first << " " << conn.second << endl;
    }

    return 0;
}

      