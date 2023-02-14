// Leetcode problem link
// https://leetcode.com/problems/concatenated-words/

class Solution {
    unordered_map<string, bool> mp;
    bool isConcatenated(string& word, unordered_set<string>& st)
    {
        if(mp.count(word)>0)
            return mp[word];

        int n = word.size();
        for(int i=0; i<n; i++)
        {
            string prefix = word.substr(0, i+1);
            string suffix = word.substr(i+1);

            if((st.count(prefix)>0 && st.count(suffix)>0) || (st.count(prefix)>0 && isConcatenated(suffix, st)))
                return mp[word] = true;
        }
        return mp[word] = false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> result;

        for(string& word : words)
        {
            if(isConcatenated(word, st))
                result.push_back(word);
        }
        return result;
    }
};
