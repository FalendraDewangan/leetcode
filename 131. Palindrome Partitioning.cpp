// Link to leetcode problem
// https://leetcode.com/problems/palindrome-partitioning

class Solution {

    bool isPalindrome(string& s, int i, int j)
    {
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            
            i++;
            j--;
        }
        return true;
    }
    
    void solve(string& s, vector<string>& temp, vector<vector<string>>& ans, int i)
    {
        if(i==s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int k=i; k<s.size(); k++)
        {
            if(isPalindrome(s, i, k))
            {
                temp.push_back(s.substr(i,k-i+1));
                solve(s, temp, ans, k+1);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, temp, ans, 0);
        return ans;
    }
};
