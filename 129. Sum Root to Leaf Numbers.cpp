// Leetcode problem link
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// O(N) Time Complexity
// O(N) Space complexity

class Solution {
    void help(TreeNode* root, int& tempSum, int& totalSum)
    {
        if(root==NULL) return;
        tempSum = tempSum*10+root->val;
        if(root->left==NULL && root->right==NULL)
           totalSum+=tempSum;

        help(root->left, tempSum, totalSum);
        help(root->right, tempSum, totalSum);
        tempSum /= 10;
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans=0;
        int temp = 0;
        help(root, temp, ans);
        return ans;
    }
};
