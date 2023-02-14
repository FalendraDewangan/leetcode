// Leetcode problem link
// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
    bool checkComponent(vector<vector<int>>& graph, int root, vector<bool>& visited)
    {
        queue<int> q;
        q.push(root);
        visited[root] = 1;
        vector<int> color(graph.size(), -1);
        color[root] = 0;

        while(!q.empty())
        {
            int frnt = q.front();
            q.pop();

            for(auto adj : graph[frnt])
            {
                
                if(color[adj] == color[frnt])
                    return false;
                if(visited[adj]==0)
                {
                    visited[adj] = 1;
                    q.push(adj);
                }
                   
                color[adj] = !color[frnt];
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, 0);

        // Applying graph coloring concept here (two color for partitioning into two sets)
        for(int i=0; i<n; i++)
        {
            if(visited[i]==0)
            {
                bool ans = checkComponent(graph, i, visited);
                if(!ans)
                    return false;
            }   
        }
        return true;
    }
};
