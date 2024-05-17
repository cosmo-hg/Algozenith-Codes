#include<bits/stdc++.h>
using namespace std;

int n;
int queens[10];
char board[10][10];

bool check(int row,int col){
    for(int pr=0;pr<row;pr++){
        int pc=queens[pr];
        if(pc==col||abs(row-pr)==abs(col-pc)){
            return 0;
        }
    }return 1;
}

int rec(int level){
    //base case
    if(level==n){
        return 1;
    }
    int ans=0;
    for(int ch=0;ch<n;ch++){
        if(board[level][ch] == '.' && check(level,ch)){
            queens[level]=ch;//move
            ans+=rec(level+1);// next level using recursion
            queens[level]=-1; //unplace
            
        }
    }return ans;
    
}

void solve(){
    n=8;
    memset(queens,-1,sizeof(queens));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    cout<<rec(0)<<endl;
}

int main(){
    solve();
}