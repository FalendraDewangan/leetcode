// Leetcode problem link
// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
    bool possible(vector<int>& piles, int h, int k)
    {
        int ans = 0;
        for(auto pile : piles)
            ans += ceil((pile*1.0)/k);

        return ans <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = INT_MAX;
        int ans;

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(possible(piles, h, mid))
            {
                ans = mid;
                e = mid-1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};
