// Leetcode problem link
// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/


// Solution 1 : Brute force
class Solution {
    int solveRec(vector<vector<int>>& piles, int k, vector<int>& top)
    {
        int ans = 0;
        if(k==0)
            return 0;

        for(int i=0; i<top.size(); i++)
        {
            if(top[i] < piles[i].size())
            {
                top[i]++;
                ans = max(ans, piles[i][top[i]-1] + solveRec(piles, k-1, top));
                top[i]--;  
            }
        }
        return ans;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> top(piles.size(),0);
        return solveRec(piles, k, top);
    }
};


// Solution 2 : another brute force
class Solution {
    int solveRec(vector<vector<int>>& piles, int k, int i)
    {
        if(i==piles.size() || k==0)
            return 0;

        // Do not take any coin from this pile
        int notTaken = solveRec(piles, k, i+1);

        // Take 1---k coins from this pile and rest from other piles
        int sum = 0;
        int taken = 0;
        // int mini = min(piles[i].size(), k);
        for(int coin = 0; coin < piles[i].size(); coin++)
        {
            sum += piles[i][coin];
            if(k-coin-1 >= 0)
                taken = max(taken, sum+solveRec(piles, k-coin-1, i+1));
        }
        return max(notTaken, taken);
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        return solveRec(piles, k, 0);
    }
};

// Solution 3: By dynamic programming and recursion
class Solution {
    int solveRec(vector<vector<int>>& piles, int k, int i, vector<vector<int>>& dp)
    {
        if(i==piles.size() || k==0)
            return 0;

        if(dp[k][i] != -1)
            return dp[k][i];

        // Do not take any coin from this pile
        int notTaken = solveRec(piles, k, i+1, dp);

        // Take 1---k coins from this pile and rest from other piles
        int sum = 0;
        int taken = 0;
        // int mini = min(piles[i].size(), k);
        for(int coin = 0; coin < piles[i].size(); coin++)
        {
            sum += piles[i][coin];
            if(k-coin-1 >= 0)
                taken = max(taken, sum+solveRec(piles, k-coin-1, i+1, dp));
        }
        return dp[k][i] = max(notTaken, taken);
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(k+1, vector<int>(piles.size(), -1));
        return solveRec(piles, k, 0, dp);
    }
};


// Solution 4 : Optimal By dynamic programming with iteration
class Solution {
    int solveTab(vector<vector<int>>& piles, int k)
    {
        vector<vector<int>> dp(k+1, vector<int>(piles.size()+1, 0));
        int ans = 0;

        for(int k1 = 1; k1 <= k; k1++)
        {
            for(int i = piles.size()-1; i>=0; i--)
            {
                // Do not take any coin from this pile
                int notTaken = dp[k1][i+1];

                // Take 1---k coins from this pile and rest from other piles
                int sum = 0;
                int taken = 0;
                for(int coin = 0; coin < piles[i].size(); coin++)
                {
                    sum += piles[i][coin];
                    if(k1-coin-1 >= 0)
                        taken = max(taken, sum + dp[k1-coin-1][i+1]);
                }
                dp[k1][i] = max(notTaken, taken);
                ans = max(ans, dp[k1][i]);
            }
        }
        return ans;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        return solveTab(piles, k);
    }
};
