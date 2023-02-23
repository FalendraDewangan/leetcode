// Leetcode Problem link
// https://leetcode.com/problems/ipo/


class Solution {
    int usingHeap(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        priority_queue<int> pq;     // Its top will contain the maximum profit that we can get with the w amount available at that time
        vector<pair<int, int>> capProf;     // it will contain the pair of capital and profits to sort the pair according to the capital

        for(int i=0; i<capital.size(); i++)
            capProf.push_back({capital[i], profits[i]});

        sort(capProf.begin(), capProf.end());

        int i=0;
        while(k)
        {
            // Adding the profits in priority queue that we will get with the w capital
            while(i<capital.size() && capProf[i].first <= w)
            {
                pq.push(capProf[i].second);
                i++;
            }
            
            if(pq.empty())
                break;
            
            w += pq.top();      // Adding the profit to our capital
            pq.pop();
            k--;
        }
        return w;
    }

    int solveRec(int k, int w, vector<int>& profits, vector<int>& capital, vector<bool>& finished)
    {
        if(k==0)
            return w;
        
        int ans = w;
        for(int i=0; i<capital.size(); i++)
        {
            if(finished[i]==0 && capital[i] <= w)
            {
                finished[i] = 1;
                ans = max(ans, solveRec(k-1, w+profits[i], profits, capital, finished));
                finished[i] = 0;
            }
        }
        return ans;
    }
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // // Solution 1 : Recursive Solution
        // vector<bool> finished(capital.size(), 0);
        // return solveRec(k, w, profits, capital, finished);


        // Solution 2 : Greedy approach using heap(priority queue)
        // O(n long n) Time Complexity and O(n) space complexity
        return usingHeap(k, w, profits, capital);
    }
};
