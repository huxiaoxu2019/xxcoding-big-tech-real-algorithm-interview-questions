// https://leetcode.cn/problems/permutations-ii/
class Solution {
public:

    void helper(vector<int>& nums, vector<bool>& vis, vector<int>& result, vector<vector<int>>& results) {
        if (result.size() == nums.size()) {
            results.push_back(result);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !vis[i-1]) continue;
            result.push_back(nums[i]);
            vis[i] = true;
            helper(nums, vis, result, results);
            vis[i] = false;
            result.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        vector<bool> vis(nums.size(), false);
        sort(nums.begin(), nums.end());
        helper(nums, vis, result, results);
        return results;
    }
};