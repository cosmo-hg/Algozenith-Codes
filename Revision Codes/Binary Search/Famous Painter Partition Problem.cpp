#include <bits/stdc++.h>
using namespace std;

#define int long long

int binarysearch(int n, int k, vector<int>& arr) {
    int lo = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0LL);
    int ans = high;

    while (lo <= high) {
        int mid = lo + (high - lo) / 2;
        int cursum = 0;
        int paintercnt = 1;
        
        for (int j = 0; j < n; j++) {
            if (cursum + arr[j] > mid) {
                paintercnt++;
                cursum = arr[j];
                if (paintercnt > k) {
                    break;
                }
            } else {
                cursum += arr[j];
            }
        }

        if (paintercnt <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        cout << binarysearch(n, k, arr) << "\n";
    }
    return 0;
}
