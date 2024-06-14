#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int> (m)); // m vector has all the values 0 assigned
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> vis(n,vector<int>(m,1e9)); // here the m vector has 1e9 value assigned
    queue <pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                vis[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int i = cur.first;
        int j=cur.second;
        if(i && grid[i-1][j] !=0){
            if(vis[i-1][j]==1e9){ // checks if cell is visited or not
                vis[i - 1][j] = vis[i][j] + 1;
                q.push({i - 1, j});
            }
        }
        if(i+1<n && grid[i+1][j] !=0){
            if(vis[i+1][j]==1e9){ // checks if cell is visited or not
                vis[i + 1][j] = vis[i][j] + 1;
                q.push({i + 1, j});
            }
        }
        if(j && grid[i][j-1] !=0){
            if(vis[i][j-1]==1e9){ // checks if cell is visited or not
                vis[i][j-1] = vis[i][j] + 1;
                q.push({i, j-1});
            }
        }
        if(j+1<m && grid[i][j+1] !=0){
            if(vis[i][j+1]==1e9){ // checks if cell is visited or not
                vis[i][j+1] = vis[i][j] + 1;
                q.push({i, j+1});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0) {
                ans = max(ans, vis[i][j]);
            }
        }
    }
    if (ans == 1e9)
        ans = -1;
    cout << ans;
}


      
