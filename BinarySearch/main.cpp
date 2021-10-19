#include <algorithm>
#include <iostream>
#include <vector>

// https://leetcode.com/problems/binary-search/

class Solution {
 public:
  // Using STL
  int BinarySearchStlBased(std::vector<int>& nums, int target) {
    auto it = std::lower_bound(nums.begin(), nums.end(), target);
    auto item_index = -1;
    if (it != nums.end() && !(target < *it))
      item_index = std::distance(nums.begin(), it);
    return item_index;
  }

  // Base on direct access
  int BinarySearch(std::vector<int>& nums, int target) {
    int pivot, left = 0, right = nums.size() - 1;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      if (nums[pivot] == target) return pivot;
      if (target < nums[pivot])
        right = pivot - 1;
      else
        left = pivot + 1;
    }
    return -1;
  }
};

int main() {
  Solution s;
  std::vector<int> nums{-1, 0, 3, 5, 9, 12};

  {
    constexpr auto kTarget = 9;
    std::cout << s.BinarySearchStlBased(nums, kTarget) << std::endl;
  }

  {
    constexpr auto kTarget = 2;
    std::cout << s.BinarySearchStlBased(nums, kTarget) << std::endl;
  }

  return 0;
}