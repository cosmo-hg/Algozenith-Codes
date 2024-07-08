#include<bits/stdc++.h>
using namespace std;

void enqueue(stack<int>& s1,stack<int>& s2, int num){
    s1.push(num);
}

void dequeue(stack<int>& s1,stack<int>& s2){
    if(s2.empty()){
        while(!s1.empty()){ // if s2 is empty and s1 is not move elements of s1 to s2 to maintain queue order
            s2.push(s1.top());
            s1.pop();
        }
    }
    if(!s2.empty()){
        s2.pop();
    }
}

void print(stack<int>& s1,stack<int>& s2){
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    if(!s2.empty()){
        cout << s2.top() << endl;
    }
}

int main(){
    int q;
    cin >> q;
    stack<int> s1,s2;
    int query;
    for(int i=0;i<q;i++){
        cin >> query;
        if(query==1){
            int x;
            cin >> x;
            enqueue(s1,s2,x);
        }
        if(query == 2){
            dequeue(s1,s2);
        }
        if(query == 3){
            print(s1,s2);
        }
    }
}