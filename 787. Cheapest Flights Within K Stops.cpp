// Leetcode problem link
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
    void makeGraph(vector<list<pair<int, int>>>& graph, vector<vector<int>>& flights)
    {
        for(vector<int>& flight : flights)
            graph[flight[0]].push_back({flight[1], flight[2]});
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // // Solutin 1
        // vector<list<pair<int, int>>> graph(n);
        // makeGraph(graph, flights);

        // queue<pair<int, int>> q;
        // int minPrice = INT_MAX;
        // q.push({src, 0});    // reached station , price

        // while(k-- != -1 && !q.empty())
        // {
        //     int n = q.size();
        //     while(n--)
        //     {
        //         pair<int, int> fr = q.front();
        //         q.pop();

        //         for(auto& adj : graph[fr.first])
        //         {
        //             q.push({adj.first, fr.second + adj.second});
        //             if(adj.first == dst)
        //                 minPrice = min(minPrice, fr.second + adj.second);
        //         }
        //     }
        // }

        // return minPrice == INT_MAX ? -1 : minPrice;


        // Solution 2 
        vector<list<pair<int, int>>> graph(n);
        vector<int> distance(n, INT_MAX);
        makeGraph(graph, flights);

        queue<pair<int, int>> q;
        q.push({src, 0});

        while(k-- != -1)
        {
            int n = q.size();
            while(n-- && !q.empty())
            {
                pair<int, int> fr = q.front();
                q.pop();

                for(auto& adj : graph[fr.first])
                {
                    if(distance[adj.first] > fr.second + adj.second)
                    {
                        q.push({adj.first, fr.second + adj.second});
                        distance[adj.first] = min(distance[adj.first], fr.second + adj.second);
                    }
                }
            }
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
