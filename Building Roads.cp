#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int const N = 100100;
int inf = 1e9;
int mod = 1e9 + 7;
vector<vector<int>> g;
vector<int> vis;

void dfs(int node,int num_cnt){
    vis[node]=1;
    for(auto x : g[node]){
        if(vis[x]==0){
            dfs(x,num_cnt);
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    vis.resize(n+1,0);
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int num_cnt = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            num_cnt ++;
            dfs(i,num_cnt);
        }
    }
    cout << num_cnt -1 << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
      