// Leetcode problem link
// https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0,sum=0;
        vector<int> ans;
        for(int i=num.size()-1; i>=0 || k!=0 ; i--)
        {
            if(i>=0)
            {
                sum = num[i] + k%10 + carry;
            }
            else{
                sum = k%10 + carry;
            }
            carry = sum/10;
            ans.push_back(sum%10);
            k /= 10;
        }
        if(carry) ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
