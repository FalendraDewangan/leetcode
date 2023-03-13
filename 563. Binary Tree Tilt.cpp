// Leetcode problem link
// https://leetcode.com/problems/binary-tree-tilt/

// O(N) Time complexity
// O(N) Space complexity

class Solution {
    int solve(TreeNode* root, int& ans)
    {
        if(!root)
            return 0;
        
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        ans += abs(left-right);
        return left + right + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
