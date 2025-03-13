// LeetCode #1: Two Sum
// Problem: Find two indices where nums[i] + nums[j] equals target
// Time: O(n), Space: O(n)
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // value: index
    for (int i = 0; i < nums.size(); i++) {
        if (map.count(target - nums[i])) return {map[target - nums[i]], i};
        map[nums[i]] = i;
    }
    return {};
}