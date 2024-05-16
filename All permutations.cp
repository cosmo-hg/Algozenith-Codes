#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void permute(std::vector<int>& nums, int start, int end, std::set<std::vector<int>>& result) {
    if (start == end) {
        result.insert(nums);
    } else {
        for (int i = start; i <= end; i++) {
            std::swap(nums[start], nums[i]);
            permute(nums, start + 1, end, result);
            std::swap(nums[start], nums[i]); // backtrack
        }
    }
}

void printPermutations(std::vector<int>& nums) {
    std::set<std::vector<int>> result;
    permute(nums, 0, nums.size() - 1, result);
    for (const auto& perm : result) {
        for (int num : perm) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    printPermutations(nums);
    return 0;
}





