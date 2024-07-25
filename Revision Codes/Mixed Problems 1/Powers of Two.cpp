#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            m[a[i]]++;
        }
        int x = 1;
        int ans = 0;
        for (int j = 0; j < 32; ++j) {
            for (int i = 0; i < n; ++i) {
                m[a[i]]--;
                if(m.count(x - a[i])) {
                    ans += m[x-a[i]];
                }
            }
            for (int i = 0; i < n; ++i) {
                m[a[i]]++;
            }
            x *= 2;
        }
        cout << ans << "\n";
    }
    return 0;
}
