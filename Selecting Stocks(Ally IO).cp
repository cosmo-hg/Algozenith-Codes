#include<bits/stdc++.h>
using namespace std;

int maxProfit(int n,int s,vector<int>& current,vector<int>& future){
    vector<int> profit(n); // possible reason of an runtime error is not putting a (n) at the end 
    vector<int> dp(s+1,0);
    for(int i=0;i<n;i++){
        profit[i] = future[i] - current[i];
    }
    for(int i=0;i<n;i++){
        if(profit[i] > 0){
            for(int j=s;j>=current[i];j--){
                dp[j] = max(dp[j], dp[j - current[i]]+ profit[i]); // main logic
            }
        }
    }
    return dp[s];
}

int main(){
    int n,s;
    cin >> n >> s;
    vector<int> current(n);
    vector<int> future(n);
    for(int i=0;i<n;i++){
        cin >> current[i];
    }
    for(int j=0;j<n;j++){
        cin >> future[j];
    }

    cout << maxProfit(n,s,current,future)<< endl;
    return 0;
}