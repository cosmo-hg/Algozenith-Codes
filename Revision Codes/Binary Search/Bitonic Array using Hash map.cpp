#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, Q;
        cin >> n >> Q;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        // Store positions of each element
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; ++i)
            positions[arr[i]].push_back(i + 1); // Positions are 1-indexed

        for (int i = 0; i < Q; ++i) {
            int K;
            cin >> K;
            // Check if K exists in the array
            if (positions.find(K) != positions.end()) {
                // Print all positions of K
                for (int pos : positions[K])
                    cout << pos << " ";
                cout << endl;
            } else {
                // If K does not exist in the array
                cout << "Not Found" << endl;
            }
        }
    }
    return 0;
}