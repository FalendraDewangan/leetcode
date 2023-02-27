// Leetcode problem link
// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

class Solution {
    void makeGraph(vector<vector<int>>& graph, vector<vector<int>>& edges)
    {
        for(vector<int>& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }

    int solve(vector<vector<int>>& graph, vector<bool>& hasApple, int curr, int parent)
    {
        int time = 0;

        for(int& child : graph[curr])
        {
            if(child != parent)
            {
                int timeByChild = solve(graph, hasApple, child, curr);
                if(timeByChild > 0 || hasApple[child])
                    time += timeByChild + 2;
            }
        }
        return time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        makeGraph(graph, edges);

        return solve(graph, hasApple, 0, -1);
    }
};
