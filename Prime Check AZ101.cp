#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        bool is_prime = 1;
        for(int j=2; j * j <= n;j++){
            if(n%j == 0){
                is_prime = 0;
            }
        }
        if(n == 1 || is_prime == 0){
            cout << "NO\n"; 
        }else{
            cout << "YES\n";
        }
    }
    return 0;
}