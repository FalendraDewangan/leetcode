// Leetcode problem link
// https://leetcode.com/problems/predict-the-winner/

//     Time complexity : O(2^n)
//     Space complexity : O(n)


class Solution {
    bool solveRec(vector<int>& nums, int s, int e, bool player, vector<int>& score)
    {
        if(s == e && player == 0)
            return score[0] + nums[s] >= score[1];
        
        if(s==e && player == 1)
            return score[1] + nums[s] > score[0];

        score[player] += nums[s];
        bool op1 = solveRec(nums, s+1, e, !player, score);
        score[player] -= nums[s];

        score[player] += nums[e];
        bool op2 = solveRec(nums, s, e-1, !player, score);
        score[player] -= nums[e];

        return !op1 || !op2;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<int> score(2, 0);
        return solveRec(nums, 0, nums.size()-1, 0, score);
    }
};
