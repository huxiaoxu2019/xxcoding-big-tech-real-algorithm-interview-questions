// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/
class Solution {
public:
    int findMin(vector<int>& nums) {
        // [4,5,6,7,0,1,2]
        // if nums[m] > nums.end()
        //   l = m + 1
        // if nums[m] < nums.end()
        //   r = m
        int l=0, r=nums.size()-1, m, n=nums.size();
        while (l<r) {
            m = l + (r-l) / 2;
            if (nums[m] > nums[n-1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};
