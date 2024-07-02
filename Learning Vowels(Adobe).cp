#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

// Function to calculate the number of words with at most K contiguous vowels
int countWords(int N, int K) {
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, 0));
    dp[0][0] = 1; // Base case
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            // Add a consonant (5 possibilities for vowels and 21 for consonants)
            dp[i][0] = (dp[i][0] + dp[i-1][j] * 21) % MOD;
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1] * 5) % MOD;
            }
        }
    }
    
    long long result = 0;
    for (int j = 0; j <= K; ++j) {
        result = (result + dp[N][j]) % MOD;
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        cout << countWords(N, K) << endl;
    }
    
    return 0;
}
