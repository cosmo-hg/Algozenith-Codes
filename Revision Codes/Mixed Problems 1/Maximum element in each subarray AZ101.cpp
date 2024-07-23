
#include<bits/stdc++.h>
using namespace std;
void solve(){
	deque<int> dq;
	int N,K;
	cin>>N>>K;
	int A[N];
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	for(int i=0;i<K-1;i++){
		while(!dq.empty() && dq.back()<A[i]){
			dq.pop_back();
		}

		dq.push_back(A[i]);
	}
	for(int i=K-1;i<N;i++){
		while(!dq.empty() && dq.back()<A[i]){
			dq.pop_back();
		}
		dq.push_back(A[i]);
		cout<<dq.front()<<" ";
		if(dq.front()==A[i-K+1]){
			dq.pop_front();
		}
	}
	cout<<"\n";
  }

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}
