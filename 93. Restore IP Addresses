// Link to leetcode problem
// https://leetcode.com/problems/restore-ip-addresses/

class Solution {
    bool isValid(string& t)
    {
        if(t.size()==1)
            return true;
            
        if(t[0]=='0')
            return false;

        if(stoi(t)>=0 && stoi(t)<=255)
            return true;
        
        return false;
    }

    void solve(string& s, string temp, vector<string>& ans, int i, int parts)
    {
        if(parts==0 && i==s.size())
        {
            ans.push_back(temp);
            return;
        }

        else if(parts==0)
            return;

        string t = "";
        for(int k=i; k<i+3 && k<s.size(); k++)
        {
            t.push_back(s[k]);
            if(isValid(t))
                temp==""?solve(s, t, ans, k+1, parts-1) : solve(s, temp+"."+t, ans, k+1, parts-1);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.size()>12)
            return ans;

        solve(s, "", ans, 0, 4);
        return ans;
    }
};
