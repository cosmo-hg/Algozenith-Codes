#include <bits/stdc++.h>
using namespace std;

int numberofDivisor(int n) {
    int ans = 0;
    for (int i = 1; i * i <= n; i++) { 
        if (n % i == 0) {
            if (i * i == n) {
                ans++;
            } else {
                ans += 2;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << numberofDivisor(n) << "\n"; 
    }
    return 0;
}
