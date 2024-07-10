#include <bits/stdc++.h>
using namespace std;

int commonPrefixLength(const string& s, int start) {
    int length = 0;
    for (int i = 0; i < s.size() - start; ++i) {
        if (s[i] == s[start + i]) {
            ++length;
        } else {
            break;
        }
    }
    return length;
}

int sumOfCommonPrefixLengths(const string& s) {
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        sum += commonPrefixLength(s, i);
    }
    return sum;
}

int main() {
    int T;
    cin >> T;
    vector<string> testCases(T);

    for (int i = 0; i < T; ++i) {
        cin >> testCases[i];
    }

    for (int i = 0; i < testCases.size(); ++i) {
        cout << sumOfCommonPrefixLengths(testCases[i]) << endl;
    }

    return 0;
}
