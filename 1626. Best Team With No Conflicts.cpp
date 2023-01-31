// Leetcode problem link
// https://leetcode.com/problems/best-team-with-no-conflicts/

class Solution {
    int solveRec(vector<pair<int, int>>& players, int i, int maxIndex)
    {
        if(i < 0)
            return 0;

        int ans = 0;
        if(players[i].second <= players[maxIndex].second)
            ans = players[i].second + solveRec(players, i-1, i);

        ans = max(ans, solveRec(players, i-1, maxIndex));

        return ans;
    }

    int solveDP(vector<pair<int, int>>& players, int i, int maxIndex, vector<vector<int>>& dp)
    {
        if(i < 0)
            return 0;

        if(dp[i][maxIndex] != -1)
            return dp[i][maxIndex];

        int ans = 0;
        if(players[i].second <= players[maxIndex].second)
            ans = players[i].second + solveDP(players, i-1, i, dp);

        ans = max(ans, solveDP(players, i-1, maxIndex, dp));

        return dp[i][maxIndex] = ans;
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> players(n);
        for(int i=0; i<n; i++)
            players[i] = {ages[i], scores[i]};
        
        sort(players.begin(), players.end());
        players.push_back({INT_MAX, INT_MAX});

        // // Solution 1 : using recursion
        // return solveRec(players, n-1, n);


        // Solution 2: Using dynamic programming
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solveDP(players, n-1, n, dp);
    }
};
