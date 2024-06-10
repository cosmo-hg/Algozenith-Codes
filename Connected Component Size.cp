#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define mp make_pair

void bfs(vector<vector<int>> &arr, vector<vector<int>> &vis, int i, int j)
{
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    int n = arr.size(), m = arr[0].size();

    vis[i][j] = 2;
    int sz = 1;

    queue<pii> q;
    q.push(mp(i, j));
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if ((nx >= 0 && nx < n && ny >= 0 && ny < m) && vis[nx][ny] == 0)
            {
                vis[nx][ny] = 2, sz++;
                q.push(mp(nx, ny));
            }
        }
    }

    vis[i][j] = 1;
    if (sz == 1)
        return;
    arr[i][j] = sz;

    q.push(mp(i, j));
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if ((nx >= 0 && nx < n && ny >= 0 && ny < m) && vis[nx][ny] == 2)
            {
                vis[nx][ny] = 1, arr[nx][ny] = sz;
                q.push(mp(nx, ny));
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    // <0 -> not visited, 1 -> completed, 2 -> visited but not completed>
    vector<vector<int>> vis(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vis[i][j] = arr[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (vis[i][j] == 0)
                bfs(arr, vis, i, j);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t = 1; // number of test cases
    cin >> _t;
    while (_t--)
        solve();
}
      