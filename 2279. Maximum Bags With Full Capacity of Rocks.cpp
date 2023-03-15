// Leetcode Problem link
// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

class Solution {
    int solve(vector<int>& capacity, vector<int>& rocks, int additionalRocks, int i)
    {
        if(i<0)
            return 0;
        
        int ans = 0;

        if(capacity[i]-rocks[i] <= additionalRocks)
            ans = 1 + solve(capacity, rocks, additionalRocks - capacity[i]+rocks[i], i-1);
        
        ans = max(ans, solve(capacity, rocks, additionalRocks, i-1));
        return ans;
    }

    int solveDP(vector<int>& capacity, vector<int>& rocks, int additionalRocks, int i, vector<vector<int>>& dp)
    {
        if(i<0)
            return 0;
        
        if(dp[i][additionalRocks] != -1)
            return dp[i][additionalRocks];

        int ans = 0;

        if(capacity[i]-rocks[i] <= additionalRocks)
            ans = 1 + solveDP(capacity, rocks, additionalRocks - capacity[i]+rocks[i], i-1, dp);
        
        ans = max(ans, solveDP(capacity, rocks, additionalRocks, i-1, dp));
        return dp[i][additionalRocks] = ans;
    }

    int solveGreedy(vector<int>& capacity, vector<int>& rocks, int additionalRocks)
    {
        int n = rocks.size();
        vector<int> needed(n,0);
        for(int i=0; i<n; i++)
            needed[i] = capacity[i] - rocks[i];

        sort(needed.begin(), needed.end());

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(needed[i] <= additionalRocks)
            {
                additionalRocks -= needed[i];
                ans++;
            }
        }
        return ans;
    }
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        // Solution by using recursion
        // int n = rocks.size();
        // return solve(capacity, rocks, additionalRocks, n-1);

        // Solution with dynamic programming
        // int n = rocks.size();
        // vector<vector<int>> dp(n, vector<int>(additionalRocks+1, -1));
        // return solveDP(capacity, rocks, additionalRocks, n-1, dp);

        // Greedy Approach
        return solveGreedy(capacity, rocks, additionalRocks);
    }
};
