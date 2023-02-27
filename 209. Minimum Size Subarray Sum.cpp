// Leetcode problem link
// https://leetcode.com/problems/minimum-size-subarray-sum/


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i=0, j=0;
        int sum = 0;
        int ans = INT_MAX;


        // Storing the sum from i to j
        while(i<n && j<n)
        {
            sum += nums[j];

            // Whenever sum increases the target we increment the value of i making sum lesser and checking till the sum is greater than target
            while(i<=j && sum >= target)
            {
                ans  = min(ans, j-i+1);
                sum -= nums[i];
                i++;
            }                
            j++;
        }

        return ans==INT_MAX ? 0 : ans;
    }
};
