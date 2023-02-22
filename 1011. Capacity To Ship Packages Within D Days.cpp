// Leetcode Problem Link
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/


class Solution {
    bool solve(vector<int>& weights, int days, int& maxCap, int i)
    {
        if(days <= 0 && i < weights.size())
            return false;
        
        if(days>=0 && i>=weights.size())
            return true;

        int used = 0, temp;
        for(temp=i; temp<weights.size(); temp++)
        {
            if(used + weights[temp] > maxCap)
                return solve(weights, days-1, maxCap, temp);
            used += weights[temp];
        }
        return true;
    }

    bool solveIterative(vector<int>& weights, int days, int& maxCap)
    {
        int used = 0;
        for(int i=0; i<weights.size(); i++)
        {
            if(used + weights[i] > maxCap)
            {
                days--;
                used = 0;
            }
                
            if(days <= 0 || weights[i] > maxCap)
                return false;

            used += weights[i];
        }
        return true;
    }
  
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // // Solution 1 : Checking whether it is possible with given capacity throught recursive function
        // // O(n) time and O(n) space complexity
        // for(int cap=maxEle; cap<INT_MAX; cap++)
        // {
        //     if(solve(weights, days, cap, 0))
        //         return cap;
        // }
        // return -1;

        // // Solution 2 : Checking whether it is possible with given capacity throught Iterative function
        // // O(n) time Complexity and O(1) space complexity
        // for(int cap=maxEle; cap<INT_MAX; cap++)
        // {
        //     if(solveIterative(weights, days, cap))
        //         return cap;
        // }
        // return -1;

        // // Solution 3 : Using binary SEarch Approach
        // // O(n) time complexity and O(1) space complexity;
        int s = 1, e = INT_MAX;
        int ans = -1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(solveIterative(weights, days, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};
