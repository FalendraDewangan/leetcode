// Leetcode Problem link 
// https://leetcode.com/problems/find-duplicate-subtrees/


// O(n^2) Time complexity
// O(n) Space complexity

class Solution {
    string solve(TreeNode* root, vector<TreeNode*>& ans, unordered_map<string, int>& um)
    {
        if(!root)
            return "N";

        string str = to_string(root->val) + "'" +solve(root->left, ans, um) + "'" +solve(root->right, ans, um);

        if(um[str] == 1)
            ans.push_back(root);
        
        um[str]++;
        return str;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> um;
        vector<TreeNode*> ans;

        solve(root, ans, um);
        return ans;
    }
};
