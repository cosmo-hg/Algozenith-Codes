#include <bits/stdc++.h>

using namespace std;

long long getSubarrays(int n, int k, vector<int> &arr) {
    unordered_map<int, int> freq;
    long long ans = 0, unique = 0, start = 0;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
        if (freq[arr[i]] == 1)
            unique++;
        while (unique > k) {
            freq[arr[start]]--;
            if (freq[arr[start]] == 0) {
                freq.erase(arr[start]);
                unique--;
            }
            start++;
        }
        ans += i - start + 1;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << getSubarrays(n, k, arr) << endl;
    }
    return 0;
}