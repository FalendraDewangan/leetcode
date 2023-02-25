// Leetcode problem link
// https://leetcode.com/problems/non-decreasing-subsequences/

class Solution {
    int n;
    void solve(vector<int>& nums, multiset<int>& temp, set<multiset<int>>& st, int i, int maxi)
    {
        if(i>=nums.size())
        {
            if(temp.size()>1)
                st.insert(temp);
            return;
        }
        // Take this element if possible
        if(nums[i] >= maxi)
        {
            temp.insert(nums[i]);
            solve(nums, temp, st, i+1, nums[i]);
            auto it = temp.find(nums[i]);
            temp.erase(it);
        }

        // Do not take this element
        solve(nums, temp, st, i+1, maxi);
    }

    void solveRecursion(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int idx)
    {
        if(curr.size() > 1)
            ans.push_back(curr);

        unordered_set<int> used;

        for(int i=idx; i<n; i++)
        {
            if((curr.empty() || curr.back() <= nums[i]) && used.count(nums[i])==0)
            {
                curr.push_back(nums[i]);
                solveRecursion(nums, curr, ans, i+1);
                curr.pop_back();
                used.insert(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        // // Solution 1 
        // multiset<int> temp;
        // set<multiset<int>> st;

        // vector<vector<int>> ans;

        // solve(nums, temp, st, 0, INT_MIN);

        // for(auto& vec : st)
        // {
        //     vector<int> ansEle;
        //     for(auto& ele : vec)
        //         ansEle.push_back(ele);
        //     ans.push_back(ansEle);
        // }
        // return ans;


        // Solution 2
        vector<vector<int>> ans;
        vector<int> curr;

        solveRecursion(nums, curr, ans, 0);
        return ans;
    }
};
