// Leetcod problem link
// https://leetcode.com/problems/possible-bipartition/



//     Time complexity : O(n)

//     Space complexity : O(n)

class Solution {

    void makeAdjList(vector<vector<int>>& dislikes, vector<list<int>>& adjList)
    {
        for(auto edge : dislikes)
        {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    bool graphColoringBFS(int n, vector<vector<int>>& dislikes, int node, vector<bool>& visited)
    {
        vector<list<int>> adjList (n+1);
        vector<int> color(n+1, -1);
        makeAdjList(dislikes, adjList);

        queue<int> q;
        q.push(node);
        color[node] = 1;
        visited[node] = 1;

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto adj : adjList[front])
            {
                if(color[front] == color[adj]) 
                    return false;
            }

            for(auto adj : adjList[front])
            {
                if(color[adj]==-1)
                {
                    visited[adj] = 1;
                    color[adj] = !color[front];
                    q.push(adj);
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<bool> visited(n+1, 0);
        bool ans = true;
        for(int i=1; i<n; i++)
        {
            if(visited[i]==0)
                ans = ans && graphColoringBFS(n, dislikes, i, visited);
        }
            
        
        return ans;
        
    }
};
