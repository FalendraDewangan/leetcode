// Leetcode problem link
//https://leetcode.com/problems/jump-game-iv/


class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<bool> visited(n, 0);
        unordered_map<int, vector<int>> um;

        for(int i=0; i<n; i++)
            um[arr[i]].push_back(i);

        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while(!q.empty())
        {
            int siz = q.size();

            while(siz--)
            {
                int front = q.front();
                q.pop();

                if(front == n-1)
                    return ans;

                if(front-1 >= 0 && !visited[front-1])
                {
                    q.push(front-1);
                    visited[front-1] = 1;
                }
                    
                
                if(front+1 < n && !visited[front+1])
                {
                    q.push(front+1);
                    visited[front+1] = 1;
                }
                

                for(int& same : um[arr[front]])
                {
                    if(!visited[same])
                    {
                        visited[same] = 1;
                        q.push(same);
                    }       
                }

                // If we do not erase this then we wiil be checking for it in future again even it is included in queue this will cause TLE
                um.erase(arr[front]);
            }
            ans++;
        }

        return -1;
    }
};
