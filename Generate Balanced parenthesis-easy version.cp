#include <bits/stdc++.h>
using namespace std;

void generate_parentheses(int n, int open, int close, string str, vector<string> &result) {
    if (open == n / 2 && close == n / 2) {
        result.push_back(str);
        return;
    }

    if (open < n / 2)
        generate_parentheses(n, open + 1, close, str + '(', result);

    if (close < open)
        generate_parentheses(n, open, close + 1, str + ')', result);
}

vector<string> print_parentheses(int n) {
    vector<string> result;
    generate_parentheses(n, 0, 0, "", result);
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<string> balanced_parentheses = print_parentheses(n);

    for (const auto &parenthesis : balanced_parentheses) {
        cout << parenthesis << endl;
    }

    return 0;
}