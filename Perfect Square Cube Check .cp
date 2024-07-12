#include<bits/stdc++.h>
using namespace std;

void checkSquare(int n){
    bool is_square = false;
    for(int i=1; i*i <= n; i++){
        if(i*i == n){
            is_square = true;
            break;
        }
    }
    if(is_square){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

void checkCube(int n){
    bool is_cube = false;
    for(int i=1; i*i*i <= n; i++){
        if(i*i*i == n){
            is_cube = true;
            break;
        }
    }
    if(is_cube){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int q, n;
        cin >> q >> n;
        if(q == 1){
            checkSquare(n);
        }
        if(q == 2){
            checkCube(n);
        }
    }
}
