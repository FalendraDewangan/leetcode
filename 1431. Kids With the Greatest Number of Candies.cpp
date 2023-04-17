// Leetcode problem link
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

// Time complexity O(N)     -----> N = number of element in candies array
// Space Complexity O(N)

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(), 0);
        int maxi = *(max_element(candies.begin(), candies.end()));
        for(int i=0; i<candies.size(); i++)
        {
            if(candies[i]+extraCandies >= maxi)
                ans[i] = 1;
        }
        return ans;
    } 
};
