// https://leetcode.cn/problems/permutations-ii/class Solution 
{
public:

    void helper(vector<pair<int, int>>& nums, vector<int>& result, vector<vector<int>>& results, int target_size) {
        if (result.size() == target_size) {
            results.push_back(result);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i].second == 0) continue;
            result.push_back(nums[i].first);
            nums[i].second--;
            helper(nums, result, results, target_size);
            nums[i].second++;
            result.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> nums_map;
        for (auto& n:nums) {
            nums_map[n]++;
        }
        vector<pair<int, int>> nums_pair;
        for (auto&pa:nums_map) {
            nums_pair.push_back({pa.first, pa.second});
        }
        vector<vector<int>> results;
        vector<int> result;
        helper(nums_pair, result, results, nums.size());
        return results;
    }
};