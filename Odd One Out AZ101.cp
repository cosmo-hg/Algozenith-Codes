#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        int ans=0;
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            ans ^= x;
        }
        cout << ans << "\n";
    }
    return 0;
}
      