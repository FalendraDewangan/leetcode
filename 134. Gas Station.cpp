// Leetcode problem link
// https://leetcode.com/problems/gas-station/



//     Time complexity : O(n)
//     Space complexity : O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficiency = 0;
        int gasLeft = 0;
        int ans = 0;
        for(int i=0; i< gas.size(); i++)
        {
            gasLeft += gas[i] - cost[i];
            if(gasLeft < 0)
            {
                deficiency += gasLeft;
                gasLeft = 0;
                ans = i+1;
            }
        }

        if(-deficiency <= gasLeft)
            return ans;
        
        return -1;
    }
};
