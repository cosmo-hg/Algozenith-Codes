
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 1010;

int mod = 1e9 + 7;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool grid[N][N];
int distA[N][N];
queue<pair<int, int>> monsterOcc, AOcc;
pair<int, int> par[N][N];
int distMon[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    memset(grid, false, sizeof(grid));

    memset(distMon, -1, sizeof(distMon));
    memset(distA, -1, sizeof(distA));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = true;
            if (s[j] == '#')
                grid[i][j] = false;
            else if (s[j] == 'M')
            {
                distMon[i][j] = 0;
                monsterOcc.push({i, j});
            }
            else if (s[j] == 'A')
            {
                distA[i][j] = 0;
                AOcc.push({i, j});
                par[i][j] = {-1, -1};
            }
        }
    }

    while (!monsterOcc.empty())
    {
        auto it = monsterOcc.front();
        monsterOcc.pop();
        int x = it.first, y = it.second;

        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= n || y < 0 || yy >= m)
                continue;
            if (grid[xx][yy] && distMon[xx][yy] == -1)
            {
                distMon[xx][yy] = distMon[x][y] + 1;
                monsterOcc.push({xx, yy});
            }
        }
    }

    while (!AOcc.empty())
    {
        auto it = AOcc.front();
        AOcc.pop();
        int x = it.first, y = it.second;

        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || xx >= n || y < 0 || yy >= m)
                continue;
            if (grid[xx][yy] && distA[xx][yy] == -1)
            {
                distA[xx][yy] = distA[x][y] + 1;
                AOcc.push({xx, yy});
                par[xx][yy] = {x, y};
            }
        }
    }

    int finx = -1, finy = -1, findist = 1e9;

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] && distA[i][0] >= 0 && (distA[i][0] < distMon[i][0] || distMon[i][0] == -1))
        {
            finx = i;
            finy = 0;
            findist = min(findist, distA[i][0]);
        }
        if (grid[i][m - 1] && distA[i][m - 1] >= 0 && (distA[i][m - 1] < distMon[i][m - 1] || distMon[i][m - 1] == -1))
        {
            finx = i;
            finy = m - 1;
            findist = min(findist, distA[i][m - 1]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] && distA[0][i] >= 0 && (distA[0][i] < distMon[0][i] || distMon[0][i] == -1))
        {
            finx = 0;
            finy = i;
            findist = min(findist, distA[0][i]);
        }
        if (grid[n - 1][i] && distA[n - 1][i] >= 0 && (distA[n - 1][i] < distMon[n - 1][i] || distMon[n - 1][i] == -1))
        {
            finx = n - 1;
            finy = i;
            findist = min(findist, distA[n - 1][i]);
        }
    }

    if (finx == -1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        cout << findist << "\n";
        /*****************************************
        ----PRINTING PATH---
        string path = "";
        int x = finx, y = finy;
        while(true) {
            int prex = par[x][y].first;
            int prey = par[x][y].second;
            if(prex == -1 && prey == -1) break;
            if(y - prey == 1) path += 'R';
            else if(y - prey == -1) path += 'L';
            else if(x - prex == 1) path += 'D';
            else path += 'U';
            x = prex; y = prey;
        }
        reverse(path.begin(), path.end());
        cout << path << "\n";
        ******************************************/
    }

    return 0;
}
      