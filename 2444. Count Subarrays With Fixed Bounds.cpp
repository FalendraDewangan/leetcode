// Leetcode problem link
// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/


class Solution {
    long long bruteForce(vector<int>& nums, int minK, int maxK)
    {
        int n = nums.size();
        long long ans = 0;

        for(int i=0; i<n; i++)
        {
            int mini = nums[i];
            int maxi = nums[i];

            for(int j=i; j<n; j++)
            {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);

                if(mini < minK || maxK < maxi)
                    break;
                
                if(mini == minK && maxK == maxi)
                    ans++;
            }
        }
        return ans;
    }

    long long solveOptimal(vector<int>& nums, int minK, int maxK)
    {
        int n = nums.size();
        long long ans = 0;
        int maxKPos = -1;
        int minKPos = -1;
        int culpritInd = -1;

        for(int i=0; i<n; i++)
        {
            if(nums[i] < minK || nums[i] > maxK)
                culpritInd = i;

            if(nums[i] == minK)
                minKPos = i;

            if(nums[i] == maxK)
                maxKPos = i;

            int smaller = min(minKPos, maxKPos);
            int temp = smaller - culpritInd;
            ans += temp<=0 ? 0 : temp;         
        }
        return ans;
    }
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // Solution 1 : Brute force
        // return bruteForce(nums, minK, maxK);

        // Solution 2 : Optimal
        return solveOptimal(nums, minK, maxK);
    }
};
