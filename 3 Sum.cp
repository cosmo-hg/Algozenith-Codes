#include <bits/stdc++.h>
using namespace std;

// Define a long long integer type
#define ll long long

// Function to solve the problem
void solve() {
    int n;
    ll target;
    // Read the number of elements in the array and the target value
    cin >> n >> target;
    vector<ll> a(n);
    // Read the array elements
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Sort the array in ascending order
    sort(a.begin(), a.end());
    // Initialize the answer with a large value
    ll ans = LLONG_MAX;
    // Iterate over the array
    for (int i = 0; i < n - 2; i++) {
        // Initialize two pointers, one at the next element and one at the end
        int l = i + 1, r = n - 1;
        while (l < r) {
            // Calculate the sum of the current three elements
            ll sum = a[i] + a[l] + a[r];
            // If the absolute difference between the sum and the target is less than the current answer
            if (abs(sum - target) < abs(ans - target)) {
                // Update the answer
                ans = sum;
            }
            // If the sum is less than the target, move the left pointer to the right
            if (sum < target) {
                l++;
            } 
            // If the sum is greater than or equal to the target, move the right pointer to the left
            else {
                r--;
            }
        }
    }
    // Print the minimum absolute difference between the sum and the target
    cout << abs(ans - target) << endl;
}

int main() {
    int t;
    // Read the number of test cases
    cin >> t;
    // Iterate over the test cases
    while (t--) {
        // Solve the problem for each test case
        solve();
    }
    return 0;
}



