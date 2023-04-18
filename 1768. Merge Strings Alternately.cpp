// Leetcode problem link
// https://leetcode.com/problems/merge-strings-alternately/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i,j;
        i=j=0;
        string ans;
        
        while(i<word1.size() && j<word2.size())
        {
            ans = ans + word1[i] + word2[j];
            i++;
            j++;
        }

        while(i<word1.size())
            ans += word1[i++];
        
        while(j<word2.size())
            ans += word2[j++];

        return ans;
    }
};
