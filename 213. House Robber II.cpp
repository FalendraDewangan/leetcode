// Leetcode Problem link
// https://leetcode.com/problems/house-robber-ii/

class Solution {
    int solveRec(vector<int>& nums, int s, const int& e)
    {
        if(s==e)
            return nums[e];
        if(s>e)
            return 0;

        int o1 = nums[s] + solveRec(nums, s+2, e);
        int o2 = solveRec(nums, s+1, e);
        return max(o1, o2);
    }

    int solveDP(vector<int>& nums, int s, const int& e, vector<int>& dp)
    {
        if(s==e)
            return dp[s] = nums[e];
        if(s>e)
            return 0;

        if(dp[s] != -1)
            return dp[s];

        int o1 = nums[s] + solveDP(nums, s+2, e, dp);
        int o2 = solveDP(nums, s+1, e, dp);
        return dp[s] = max(o1, o2);
    }

    int solveTab(vector<int>& nums, int s, int e)
    {
        vector<int> dp(e+3, 0);

        dp[e] = nums[e];
        dp[e+1] = 0;
        dp[e+2] = 0;

        for(int i=e; i>=s; i--)
        {
            int o1 = nums[i] + dp[i+2];
            int o2 = dp[i+1];
            dp[i] = max(o1, o2);
        }
        return dp[s];
    }

    int solveTabOPT(vector<int>& nums, int s, int e)
    {
        int dp_e1 = 0;
        int dp_e2 = 0;

        for(int i=e; i>=s; i--)
        {
            int o1 = nums[i] + dp_e2;
            int o2 = dp_e1;
            dp_e2 = dp_e1;
            dp_e1 = max(o1, o2);
        }
        return dp_e1;
    }

public:
    int rob(vector<int>& nums) {
        // Special case
        if(nums.size()==1)
            return nums[0];


        // // Solution 1 Using recursion or say brute force
        // int n = nums.size()-1;
        // int e = n-1;
        // int op1 = solveRec(nums, 0, e);
        // int op2 = solveRec(nums, 1, n);
        // return max(op1, op2);




        // // Solution 2 Using dynamic programming
        // int n = nums.size();
        // vector<int> dp(n, -1);

        // int e1 = n-2;
        // int op1 = solveDP(nums, 0, e1, dp);

        // for(int i=0; i<n; i++)
        //     dp[i] = -1;

        // int e2 = n-1;
        // int op2 = solveDP(nums, 1, e2, dp);

        // return max(op1, op2);




        // // Solution 3 : optimizing memory used by recursion
        // int n = nums.size();
        // int op1 = solveTab(nums, 0, n-2);
        // int op2 = solveTab(nums, 1, n-1);

        // return max(op1, op2);




        // Solution 4 : With more memory optimization to O(1)
        int n = nums.size();
        int op1 = solveTabOPT(nums, 0, n-2);
        int op2 = solveTabOPT(nums, 1, n-1);

        return max(op1, op2);
    }
};
