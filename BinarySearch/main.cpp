#include <iostream>
#include <algorithm>
#include <vector>

// https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        auto item_index = -1;
        if (it != nums.end() && !(target < *it)) 
          item_index = std::distance(nums.begin(), it);
        return item_index;
    }
};

int main() {
  Solution s;
  std::vector<int> nums{-1,0,3,5,9,12};

  {
    constexpr auto kTarget = 9;
    std::cout << s.search(nums, kTarget) << std::endl;
  }

  {
    constexpr auto kTarget = 2;
    std::cout << s.search(nums, kTarget) << std::endl;
  }

  return 0;
}