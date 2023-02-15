// Leetcode problem link
// https://leetcode.com/problems/flip-string-to-monotone-increasing/

class Solution {
    int solveRecursion(string& s, int prev, int i)
    {
        if(i>=s.size())
            return 0;

        int ans = INT_MAX;
        if(prev==0)
        {
            if(s[i]=='0')
            {
                // Leave it 0
                ans = solveRecursion(s, 0, i+1);
                // Flip it to one
                ans = min(ans, 1 + solveRecursion(s, 1, i+1));
            }
            else
            {
                // leave it 1
                ans = solveRecursion(s, 1, i+1);
                // Flip it to 0
                ans = min(ans, 1 + solveRecursion(s, 0, i+1));
            }
        }
        else
        {
            if(s[i]=='0')
            {
                // flip it to 1
                ans = 1 + solveRecursion(s, 1, i+1);
            }
            else
            {
                // Leave it 1
                ans = solveRecursion(s, 1, i+1);
            }
        }
        return ans;
    }

    int solveDP(string& s, int prev, int i, vector<vector<int>>& dp)
    {
        if(i>=s.size())
            return dp[prev][i] = 0;

        if(dp[prev][i] != -1)
            return dp[prev][i];

        int ans = INT_MAX;
        if(prev==0)
        {
            if(s[i]=='0')
            {
                // Leave it 0
                ans = solveDP(s, 0, i+1, dp);
                // Flip it to one
                ans = min(ans, 1 + solveDP(s, 1, i+1, dp));
            }
            else
            {
                // leave it 1
                ans = solveDP(s, 1, i+1, dp);
                // Flip it to 0
                ans = min(ans, 1 + solveDP(s, 0, i+1, dp));
            }
        }
        else
        {
            if(s[i]=='0')
            {
                // flip it to 1
                ans = 1 + solveDP(s, 1, i+1, dp);
            }
            else
            {
                // Leave it 1
                ans = solveDP(s, 1, i+1, dp);
            }
        }
        return dp[prev][i] = ans;
    }

    int solveTab(string& s)
    {
        int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));

        for(int prev=1; prev>=0; prev--)
        {
            for(int i=n-1; i>=0; i--)
            {
                int ans = INT_MAX;
                if(prev==0)
                {
                    if(s[i]=='0')
                    {
                        // Leave it 0
                        ans = dp[0][i+1];
                        // Flip it to one
                        ans = min(ans, 1 + dp[1][i+1]);
                    }
                    else
                    {
                        // leave it 1
                        ans = dp[1][i+1];
                        // Flip it to 0
                        ans = min(ans, 1 + dp[0][i+1]);
                    }
                }
                else
                {
                    if(s[i]=='0')
                    {
                        // flip it to 1
                        ans = 1 + dp[1][i+1];
                    }
                    else
                    {
                        // Leave it 1
                        ans = dp[1][i+1];
                    }
                }
                dp[prev][i] = ans;
            }
        }
        return dp[0][0];
    }

    int solveTabOpt(string& s)
    {
        int countOfOne = 0;
        int flip = 0;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='1')
                countOfOne++;
            else
                flip = min(flip+1, countOfOne);
        }

        return min(flip, countOfOne);
    }

public:
    int minFlipsMonoIncr(string s) {
        // // Solution 1 By recursion
        // return solveRecursion(s, 0, 0);

        // // Solution 2 By dynamic programming
        // vector<vector<int>> dp(2, vector<int>(s.size()+1, -1));
        // return solveDP(s, 0, 0, dp);

        // Solution by optimizing memory usage(due to recursion)
        // return solveTab(s);

        //  Optimized Solution
        return solveTabOpt(s);
    }
};
