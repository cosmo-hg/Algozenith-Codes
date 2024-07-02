#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum number of unique IDs after performing M operations
int minUniqueIDs(vector<int>& arr, int M) {
    unordered_map<int, int> freq;
    
    // Count the frequency of each ID
    for (int id : arr) {
        freq[id]++;
    }

    // Store frequencies in a vector
    vector<int> freqValues;
    for (auto it : freq) {
        freqValues.push_back(it.second); // it.second takes frequency from the map
    }
    
    // Sort the frequencies in ascending order
    sort(freqValues.begin(), freqValues.end());
    
    int uniqueIDs = freqValues.size();
    
    // Remove elements by reducing the number of unique IDs
    for (int f : freqValues) {
        if (M >= f) {
            M -= f;
            uniqueIDs--;
        } else {
            break;
        }
    }
    
    return uniqueIDs;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        
        cout << minUniqueIDs(arr, M) << endl;
    }
    
    return 0;
}
