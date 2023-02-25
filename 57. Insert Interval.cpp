// Leetcode problem link
// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // // Solution 1 : Brute force method
        // // O(n^2) Time Complexity
        // // O(1) Space Compleixity

        // int i=0;
        // while(i<intervals.size())       //  --->O(n)
        // {
        //     if(intervals[i][1] < newInterval[0])
        //         i++;
        //     else if(newInterval[1] < intervals[i][0])
        //         break;
        //     else
        //     {
        //         newInterval[0] = min(newInterval[0], intervals[i][0]);
        //         newInterval[1] = max(newInterval[1], intervals[i][1]);
        //         intervals.erase(intervals.begin()+i);           //  --->O(n)
        //     }
        // }

        // intervals.insert(intervals.begin()+i,newInterval);              // --->O(n)
        // return intervals;


        // Solution 2 : Optimal method
        // // O(n) Time Complexity
        // // O(n) Space Compleixity

        vector<vector<int>> res;
        int i=0; 
        int n = intervals.size();

        while(i < n)             // --->O(n)
        {
            if(newInterval[1] < intervals[i][0])
                break;
            else if(intervals[i][1] < newInterval[0])
                res.push_back(intervals[i]);
            else
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }

        res.push_back(newInterval);

        while(i < n)             // --->O(n)
            res.push_back(intervals[i++]);

        return res;
    }
};
