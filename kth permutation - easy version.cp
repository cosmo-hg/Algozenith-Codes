#include <iostream>
#include <vector>
#include <algorithm>

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void printKthPermutation(int n, int k) {
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    int factorialN = factorial(n);
    k = k % factorialN; // handle cases where k > n!
    if (k == 0) {
        k = factorialN;
    }

    for (int i = 0; i < k - 1; i++) {
        std::next_permutation(nums.begin(), nums.end());
    }

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    printKthPermutation(n, k);
    return 0;
}







