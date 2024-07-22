#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n,x;
        cin >> n >> x;
        int arr[n];
        for(int j=0;j<n;j++){
            cin >> arr[j];
        }
        sort(arr,arr+n);
        int ans = 0;
        for(int i=0;i<n;i++){
            int k = upper_bound(arr,arr+n,x - arr[i]) - arr;
            if(arr[i] <= x - arr[i]) k--;
            ans += k;
        }    
        cout << ans << endl;
    }
    return 0;
}