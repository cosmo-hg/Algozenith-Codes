#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        multiset<int> s;
        int b=1;
        for(int j=0;j<n;j++){
            int x;
            cin >> x;
            if(x > b){
                s.insert(x);
            }
            while(!s.empty() && *s.begin() <= b){
                s.erase(s.begin());
            }
            if(s.size() > b){
                b++;
            }
            cout << b << " ";
        }
        cout << "\n";
    }
    return 0;
}