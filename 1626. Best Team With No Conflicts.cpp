// Leetcode problem link
// https://leetcode.com/problems/best-team-with-no-conflicts/

// Solution 1 : Dynamic programmig
class Solution {
    int solveDP(vector<pair<int, int>>& players, int i, int maxi, vector<vector<int>>& dp)
    {
        if(i >= players.size())
            return 0;

        if(dp[i][maxi] != -1)
            return dp[i][maxi];

        int ans = 0;
        if(players[maxi].second <= players[i].second)
            ans = players[i].second + solveDP(players, i+1, i, dp);
        
        ans = max(ans, solveDP(players, i+1, maxi, dp));
        return dp[i][maxi] = ans;
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> players(n);
        for(int i=0; i<n; i++)
            players[i] = {ages[i], scores[i]};
        
        players.push_back({0, 0});
        sort(players.begin(), players.end());

        // Dynamic programming
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solveDP(players, 1, 0, dp);
    }
};

// Solution 2 : Optimal solution
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> players(n);
        for(int i=0; i<n; i++)
            players[i] = {ages[i], scores[i]};
        
        sort(players.begin(), players.end());


        vector<int> dp(n, 0);
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int score = players[i].second;
            for(int j=i-1; j>=0; j--)
            {
                if(players[j].second <= players[i].second)
                    score = max(score, players[i].second + dp[j]);
            }
            dp[i] = score;
            ans = max(ans, score);
        }
        return ans;
    }
};
