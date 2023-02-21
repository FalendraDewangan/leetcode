// Leetcode Problem Link
// https://leetcode.com/problems/single-element-in-a-sorted-array/


class Solution {
    int solveBruteForce(vector<int>& nums)
    {
        unordered_map<int, int> count;
        for(auto ele : nums)
            count[ele]++;

        for(auto pr : count)
        {
            if(pr.second == 1)
                return pr.first;
        }
        return -1;
    }

    int solveN(vector<int>& nums)
    {
        int ans = 0;
        for(auto ele : nums)
            ans ^= ele;

        return ans;
    }

    int solveOptimal(vector<int>& nums)
    {
        int s = 0;
        int e = nums.size()-1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(s==e || (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]))
                return nums[mid];
            else if(nums[mid] == nums[mid-1] && (mid-s+1)%2!=0)
                e = mid-2;
            else if(nums[mid] == nums[mid+1] && (mid-s+2)%2 !=0){
                e = mid-1;
            }
            else{
                if(nums[mid] == nums[mid-1])
                    s=mid+1;
                else
                    s = mid+2;
            }
        }
        return -1;
    }
public:
    int singleNonDuplicate(vector<int>& nums) {

        // // // Brute Force Method (O(n) Time complexity and O(n) Space Complexity)
        // return solveBruteForce(nums);

        // // // With Space Optimization here O(n) Time Complexity and O(1) Space Complexity
        // return solveN(nums);

        // // Better Time Complexity O(log n) Time Complexity and O(1) Space Complexity
        return solveOptimal(nums);
    }
};
