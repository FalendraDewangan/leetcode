// Leetcode problem link
// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/



//     Time complexity : O(n)
//     Space complexity : O(n)

class Solution {
    void findSortestDistance(vector<int>& edges, int node, vector<int>& d)
    {
        d[node] = 0;
        queue<int> q;
        q.push(node);

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            if(edges[front] != -1 && d[front] + 1 < d[edges[front]])
            {
                q.push(edges[front]);
                d[edges[front]] = d[front] + 1;
            }  
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> d1(n, INT_MAX), d2(n, INT_MAX);

        findSortestDistance(edges, node1, d1);
        findSortestDistance(edges, node2, d2);

        int ansNode = -1;
        int ansDist = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(d1[i] != INT_MAX && d2[i] != INT_MAX && ansDist > max(d1[i], d2[i]))
            {
                ansDist = max(d1[i], d2[i]);
                ansNode = i;
            }
        }
        return ansNode;
    }
};
