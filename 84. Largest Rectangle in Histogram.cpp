// Leetcode problem link
// https://leetcode.com/problems/largest-rectangle-in-histogram/


// O(N) Time complexity
// O(N) Space complexity

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = INT_MIN;
        vector<int> left(n);
        vector<int> right(n);

        st.push(-1);
        for(int i=0; i<n; i++)
        {
            while(st.top() != -1 && heights[i] <= heights[st.top()])
                st.pop();
            
            left[i] = st.top();
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        st.push(n);
        for(int i=n-1; i>=0; i--)
        {
            while(st.top() != n && heights[i] <= heights[st.top()])
                st.pop();

            right[i] = st.top();
            st.push(i);
        }

        for(int i=0; i<n; i++)
        {
            int area = (right[i] - left[i] -1)*heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
