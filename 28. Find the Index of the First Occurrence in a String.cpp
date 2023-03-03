// Leetcode problem link
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/


class Solution {
public:
    int strStr(string haystack, string needle) {
        // O(m*n) time complexity
        // O(1) space complexity
        int ans = 0;
        int n = haystack.size(), m = needle.size();

        for(int i=0; i<=n-m; i++)
        {
            bool flag = true;
            int pos = i;
            for(int j=0; j<m; j++, pos++)
            {
                if(haystack[pos] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                return i;
        }
        return -1;
    }
};
