#include<bits/stdc++.h>
using namespace std;
#define int long long

int find_fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    int a=0 ;
    int b=1 ;
    int index = 1;
    while(b<n){
        int temp = b;
        b = a+b;
        a = temp;
        index++;
    }
    if(b==n){
        return index;
    }
    else{
        return -1;
    }
}

int32_t main(){
    int t;
    cin >> t;
    vector<int> results(t);
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        results[i] = find_fibonacci(n);
    }
    for(int result : results){
        cout << result << endl;
    }
    return 0;
}