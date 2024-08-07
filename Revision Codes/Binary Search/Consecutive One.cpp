#include<bits/stdc++.h>
using namespace std;

bool check(int mid,int k,vector<int>& arr,int n){
    int cnt = 0;
    for(int i=0;i<mid;i++){
        if(arr[i] == 0){
            cnt++;
        }
    }
    if(cnt <= k){
        return true;
    }
    for(int j=mid;j<n;j++){// Remove the effect of the element going out of the window
        if(arr[j-mid] == 0){
            cnt--;
        }// Add the effect of the new element coming into the window
        if(arr[j] == 0){
            cnt++;
        }// Check if the current window has at most k zeros
        if(cnt <= k){
            return true;
        }
    }
    return false;
}

int binarysearch(int n,vector<int>& arr,int k){
    int lo = 0;
    int high = n;
    int ans = 0;
    while(lo <= high){
        int mid = lo + (high-lo)/2;
        if(check(mid,k,arr,n)){
            ans = mid;
            lo = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    int n,k;
    int ans;
    for(int i=0;i<t;i++){
        cin >> n >> k;
        vector<int> arr(n);
        for(int j=0;j<n;j++){
            cin >> arr[j];
        }
        ans = binarysearch(n,arr,k);
    }
    cout << ans << endl;
}