#include<bits/stdc++.h>
using namespace std;

int value(char ch){
    if(ch == 'A'){
        return 1;
    }
    if(ch == 'B') return 10;
    if(ch == 'C') return 100;
    if(ch == 'D') return 1000;
    return 10000;
}

int converttoDecimal(const string& s){
    int n = s.size();
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        values[i] = value(s[i]);
    }
    
    int decimalValue = 0;
    for (int i = 0; i < n; ++i) {
        bool negative = false;
        for (int j = i + 1; j < n; ++j) {
            if (values[j] > values[i]) {
                negative = true;
                break;
            }
        }
        if (negative) {
            decimalValue -= values[i];
        } else {
            decimalValue += values[i];
        }
    }
    return decimalValue;
}

int maxNumber(string s){
    int maxValue = converttoDecimal(s);
    int n = s.size();
    string digits = "ABCDE";
    
    for(int i=0;i<n;i++){
        char original = s[i];
        for(int j=0;j<digits.size();j++){
            if(digits[j] != original){
                s[i] = digits[j];
                maxValue = max(maxValue , converttoDecimal(s));
            }
        }
        s[i] = original;
    }
    return maxValue;
}

int main(){
    string s;
    cin >> s;
    cout << maxNumber(s) << endl;
}