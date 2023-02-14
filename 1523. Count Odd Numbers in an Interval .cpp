// Leetcode problem link
// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/


class Solution {
public:
    int countOdds(int low, int high) {
        // If both number are odd
        if(low&1 && high&1)
            high++;

        int ans = high - low;
        return (ans+1)/2;
    }
};
