#include<bits/stdc++.h>
using namespace std;

void solve(){
    int q;
    cin >> q;
    stack<int> s1,s2;
    for(int i=0;i<q;i++){
        string s;
        cin >> s;
        if(s == "push"){
            int x;
            cin >> x;
            s1.push(x);
        } 
        if(s == "pop"){
            if(!s2.empty()){
                int a = s2.top();
                s2.pop();
                cout << a << endl;
            }else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                int a = s2.top();
                s2.pop();
                cout << a << endl;
            }
        } 
        if (s == "front") {
            if (!s2.empty()) {
                int a = s2.top();
                cout << a << endl;
            } else {
                while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
                }
                int a = s2.top();
                cout << a << endl;
            }
        }
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}