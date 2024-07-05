#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> prefixSum(const vector<vector<int>>& grid, int N) {
    vector<vector<int>> ps(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            ps[i][j] = grid[i-1][j-1] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1]; // formula for prefix sum matrix
        }
    }
    return ps;
}

// Function to check if there is a k x k subgrid with sum greater than maxSum
bool hasSubgridGreaterThanMaxSum(const vector<vector<int>>& ps, int N, int k, int maxSum) {
    for (int i = k; i <= N; ++i) {
        for (int j = k; j <= N; ++j) {
            int subgridSum = ps[i][j] - ps[i-k][j] - ps[i][j-k] + ps[i-k][j-k];
            if (subgridSum > maxSum) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N, maxSum;
    cin >> N >> maxSum;
    
    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> ps = prefixSum(grid, N);

    // Binary search 
    int left = 1, right = N, result = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (!hasSubgridGreaterThanMaxSum(ps, N, mid, maxSum)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}