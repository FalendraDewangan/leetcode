// Leetcode problem link
// https://leetcode.com/problems/maximum-sum-circular-subarray/

// O(N) Time complexity
// O(1) Space complexity


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // There is three case that needs to be considered
        // 1. Maximum sum is present in array itselt without using property of circular sum ---> return maxSubArraySum
        // 2. Maximum sum can be find by using curcular array property ----> return totalSum - minSubarraySum
        // 3. All the element of the array is negative than return maximumElement

        int maxSum = nums[0], currMaxSum = 0, minSum = nums[0], currMinSum = 0, totalSum = nums[0], n = nums.size();
        for(int i=0; i<n; i++)
        {
            // Kadene's algorithm for finding maximum subArraySum
            currMaxSum = max(currMaxSum + nums[i], nums[i]);
            maxSum = max(maxSum, currMaxSum);

            // Kadene's algorithm for finding minimum subArraySum
            currMinSum = min(currMinSum + nums[i], nums[i]);
            minSum = min(minSum, currMinSum);

            totalSum += nums[i];
        }

        return maxSum < 0 ? maxSum : max(maxSum, totalSum - minSum);
    }
};
