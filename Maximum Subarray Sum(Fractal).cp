#include <bits/stdc++.h>
using namespace std;

int maxsum(vector<int>& arr) {
    int current_max = arr[0];
    int max_so_far = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        current_max = max(arr[i], current_max + arr[i]);
        max_so_far = max(max_so_far, current_max);
    }
    return max_so_far;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        cout << maxsum(arr) << endl;
    }
    return 0;
}
