#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

void solve() {
    std::bitset<64> b(0); // use 64 bit instead of 60
    int q, op, x;
    std::cin >> q;

    while (q--) {
        std::cin >> op;
        op--;
        if (op == 0) {
            std::cin >> x;
            std::cout << b[x] << "\n";
        }
        else if (op == 1) {
            std::cin >> x;
            b[x] = 1;
        }
        else if (op == 2) {
            std::cin >> x;
            b[x] = 0;
        }
        else if (op == 3) {
            std::cin >> x;
            b[x] = ~b[x];
        }
        else if (op == 4) {
            std::cout << b.all() << "\n";
        }
        else if (op == 5) {
            std::cout << b.any() << "\n";
        }
        else if (op == 6) {
            std::cout << b.none() << "\n";
        }
        else if (op == 7) {
            std::cout << b.count() << "\n";
        }
        else {
            std::cout << b.to_ullong() << "\n";
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);


    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}


