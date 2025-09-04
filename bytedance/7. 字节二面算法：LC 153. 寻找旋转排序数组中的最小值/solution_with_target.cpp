// https://leetcode.cn/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // [4,5,6,7,0,1,2]
        int l=0, r=nums.size()-1, n=nums.size(), m;
        while (l<r) {
            m= l+(r-l+1)/2;
            if (nums[m] <= nums[n-1]) {
                if (target <= nums[n-1]) {
                    if (nums[m] <= target) {
                        l = m;
                    } else {
                        r =  m - 1;
                    }
                } else {
                    r = m - 1;
                }
            } else {
                // nums[m] > nums[n-1]
                if (target > nums[n-1]) {
                    if (nums[m] <= target) {
                        l = m;
                    } else {
                        r = m - 1;
                    }
                } else {
                    l = m + 1;
                }
            }
        }
        if (nums[l] != target) return -1;
        return l;
    }
};
