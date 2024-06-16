#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

const int N = 10010;
int inf = 1e9;
int mod = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        multiset<int> M;
        for(int i= 0;i < k;i++){
            M.insert(arr[i]);  
        }
        for(int i = 0; i <= n - k; i++){
            cout << *(M.rbegin()) << " ";
            M.erase(M.find(arr[i]));
            if(i + k < n){
                M.insert(arr[i + k]);
            }
        }
        cout << "\n";
    }
    return 0;
}
      