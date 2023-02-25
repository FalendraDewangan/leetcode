// Leetcode problem link
// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
    int bruteForce(vector<int>& nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                if(sum % k == 0)
                    ans++;
            }
        }
        return ans;
    }

    int solveOPT(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        mp[0] = 1;

        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            int r = sum%k;
            if(r<0)
                r += k;
            
            ans += mp[r];
            mp[r]++;
        }
        return ans;
    }
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Solution 1
        // return bruteForce(nums, k);

        // Solution 2
        return solveOPT(nums, k);
    }
};
