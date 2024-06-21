#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int m = 1 << n;
        vector<long long> arr(m);
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end());
        
        map<long long, int> sums;
        sums[0] = 1;
        
        vector<long long> ans;
        vector<long long> subsums;
        
        for (int i = 0; i < m; i++) {
            if (sums[arr[i]] > 0) {
                sums[arr[i]]--;
            } else {
                ans.push_back(arr[i]);
                vector<long long> temp;
                for (auto &sum : subsums) {
                    temp.push_back(sum + arr[i]);
                    sums[sum + arr[i]]++;
                }
                for (auto &sum : temp) {
                    subsums.push_back(sum);
                }
                subsums.push_back(arr[i]);
            }
        }
        
        for (auto &num : ans) {
            cout << num << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
