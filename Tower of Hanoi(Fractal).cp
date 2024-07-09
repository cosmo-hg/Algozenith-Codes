#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, char source, char target, char auxiliary, int& movecount) { 
    if(n == 0) return; // base case
    
    hanoi(n - 1, source, auxiliary, target, movecount); //first use auxiliary as target and target as auxiliary
    movecount++; 

    cout << "Move disk " << n << " from rod " << source << " to rod " << target << endl; 

    hanoi(n - 1, auxiliary, target, source, movecount); 
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int movecount = 0;
        hanoi(n, 'A', 'C', 'B', movecount);
        cout << endl; 
    }
    return 0;
}
