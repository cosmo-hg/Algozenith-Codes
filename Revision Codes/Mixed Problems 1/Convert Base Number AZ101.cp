#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

signed main() {
    IOS
    int t=1;
    cin >> t;
    while (t--) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        // base a to decimal
        int deci = 0;
        int pw = 1;
        for (int i = (int)s.size()-1; i >= 0; --i) {
            int x;
            if(s[i] >= '0' && s[i] <= '9') {
                x = s[i] - '0';
            }
            else {
                x = s[i] - 'A' + 10;
            }
            deci += x * pw;
            pw *= a;
        }
        // decimal to base b
        string ans;
        while(deci) {
            int x = deci % b;
            char c;
            if(x >=0 && x <= 9) {
                c = x + '0';
            }
            else {
                c = x - 10 + 'A';
            }
            ans += c;
            deci /= b;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}
