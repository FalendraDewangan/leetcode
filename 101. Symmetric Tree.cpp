// Leetcode problem link
// https://leetcode.com/problems/symmetric-tree/


// O(n) Time complexity
// O(n) Space Complexity

class Solution {
public:
    bool check(TreeNode* rootL, TreeNode* rootR)
    {
        // Base condition
        if((rootL && !rootR || (!rootL && rootR)))
            return false;
        
        if(!rootL && !rootR)
            return true;

        // Recursion
        if(rootL->val == rootR->val)
            return check(rootL->left, rootR->right) && check(rootL->right, rootR->left);
        else 
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return 1;
        
        return check(root->left, root->right);
    }
};
