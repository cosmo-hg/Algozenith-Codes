#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);

    for(int j=0;j<n;j++){
        cin >> a[j];
    }

    sort(a.begin(),a.end());

    for(int k=1;k<n;k++){
        a[k] += a[k-1];
    }

    for(int i=0;i<q;i++){
        int m;
        cin >> m;
        int idx = upper_bound(a.begin(),a.end(),m) - a.begin();
        cout << idx << "\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    for(int i=0;i<t;i++){
        solve();
    }
}
      