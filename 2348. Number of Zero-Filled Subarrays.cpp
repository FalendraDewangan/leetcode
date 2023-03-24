// Leetcode problem link
// https://leetcode.com/problems/number-of-zero-filled-subarrays/

// O(N) Time complexity
// O(1) Space complexity

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int siz = nums.size();
        for(int i=0; i<siz; )
        {
            if(nums[i]==0)
            {
                int j = i;
                while(j<siz && nums[j]==0)
                    j++;
                
                long long n = j - i;
                res += (n*(n+1))/2;
                i = j;
            }
            else 
                i++;
        }
        return res;
    }
};
