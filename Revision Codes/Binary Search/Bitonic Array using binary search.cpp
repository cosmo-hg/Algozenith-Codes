#include <bits/stdc++.h>
using namespace std;

bool check(int arr[], int i) {
    return arr[i] > arr[i - 1]; // if present > previous then peak towards right
} 

int findPeakElement(int arr[], int n) {
    int start = 1;
    int end = n - 1;
    int peak = 0;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (check(arr, mid)) {
            peak = mid; // update peak
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return peak;
}

void binarySearchIncreasing(int arr[], int start, int end, int k, vector<int>& result) //end used here is peak
{
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k) {
            result.push_back(mid + 1);
            return;
        } else if (arr[mid] > k) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
}

void binarySearchDecreasing(int arr[], int start, int end, int k, vector<int>& result) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k) {
            result.push_back(mid + 1);
            return;
        } else if (arr[mid] > k) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int peak = findPeakElement(arr, n);

    for (int k = 0; k < q; k++) {
        int x;
        cin >> x;
        vector<int> result;

        binarySearchIncreasing(arr, 0, peak, x, result);
        binarySearchDecreasing(arr, peak + 1, n - 1, x, result);

        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
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