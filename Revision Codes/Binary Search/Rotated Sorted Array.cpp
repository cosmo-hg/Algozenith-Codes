#include <bits/stdc++.h>
using namespace std;

int binarysearch(int n, vector<int>& arr) {
    int lo = 1; 
    int high = n - 1;
    int ans = 0;

    while (lo <= high) {
        int mid = lo + (high - lo) / 2;

        if (arr[mid] < arr[0]) {
            ans = mid;
            high = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = binarysearch(n, arr);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
