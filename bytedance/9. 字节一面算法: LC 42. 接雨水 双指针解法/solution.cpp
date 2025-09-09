// https://leetcode.cn/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        //  o    o o o     o o o o o     o o 
        //       p   left          right q
        //  leftMax = max(height[0 ... left])
        //  rightMax = max(height[right, ... n-1])
        //  if height[left] < height[right] // leftMax < rightMax
        //     water += (leftMax - height[left])
        //     ++left
        //  else 
        //     water += (rightMax - height[right])
        //     --right

        // height[left] < height[right], 假设 leftMax > rightMax

        // height[p] = leftMax > height[q], q in [right, n-1]
        // height[p] > height[q]

        int leftMax = 0, rightMax = 0, left = 0, right = height.size() - 1;
        int water = 0;
        while (left < right) {
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            if (height[left] < height[right]) {
                water += (leftMax - height[left]);
                ++left;
            } else {
                water += (rightMax - height[right]);
                --right;
            }
        }
        return water;
    }
};