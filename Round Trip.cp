#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 100010;

int mod = 1e9 + 7;

int n;
vector<vector<int>> adj;
vector<int> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par) { // passing vertex and its parent vertex
    color[v] = 1;
    for (int u : adj[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u, parent[u]))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle() {
    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    cycle_start = -1;

    for (int v = 1; v <= n; v++) {
        if (color[v] == 0 && dfs(v, parent[v]))
            break;
    }

    if (cycle_start == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    /***********************************************************
        --CODE TO PRINT CYCLE--
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << (int)cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    ************************************************************/
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m;
    cin >> n >> m;

    adj.resize(n + 1);
    
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_cycle();

    return 0;
}
