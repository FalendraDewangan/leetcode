// Leetcode problem link
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = prices[0];
        int profit = 0;
        for(int i=0; i<prices.size(); i++)
        {
            if(minTillNow > prices[i]) minTillNow = prices[i];
            if(prices[i]-minTillNow > profit) profit = prices[i]-minTillNow;
        }
        return profit;
    }
};
