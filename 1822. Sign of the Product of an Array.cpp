// Leetcode problem link
// https://leetcode.com/problems/sign-of-the-product-of-an-array/

// Time complexity O(N)
// Space complexity O(1)

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for(int& num : nums)
        {
            if(num==0)
                return 0;
            else if(num < 0)
                product *= -1;
        }

        return product;
    }
};
