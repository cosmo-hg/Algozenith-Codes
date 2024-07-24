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
    int q;
    cin >> q;
    set<int> s, ns;
    while (q--) {
      int t, x;
      cin >> t >> x;
      if (t == 1) {
        s.insert(x);
        ns.erase(x);
        if (!s.count(x + 1)) {
          ns.insert(x + 1);
        }
      } else {
        if (!s.count(x)) {
          cout << x << "\n";
        } else {
          cout << *ns.lower_bound(x) << "\n";
        }
      }
    }
  }
  return 0;
}
