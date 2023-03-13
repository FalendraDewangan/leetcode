// Leetcode Problem link
// https://leetcode.com/problems/validate-binary-search-tree/


// Solution 1
// O(N) Time complexity
// O(N) Space complexity
// Here using the conceot that inOrder traversal of BST is in sorted order
class Solution {
    void findInOrder(TreeNode* root, vector<int>& inOrdre)
    {
        if(!root)
            return;
        
        findInOrder(root->left, inOrdre);
        inOrdre.push_back(root->val);
        findInOrder(root->right, inOrdre);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        findInOrder(root, inOrder);

        int n = inOrder.size();
        for(int i=1; i<n; i++)
        {
            if(inOrder[i-1] >= inOrder[i])
                return false;
        }
        return true;
    }
};

// Solution 2
// O(N) Time complexity
// O(N) Space complexity
class Solution {
    bool isValid(TreeNode* root, long mini, long maxi)
    {
        if(!root)
        return true;

        if(root->val <= mini || root->val >= maxi)
            return false;
        
        return isValid(root->left, mini, root->val) && isValid(root->right, root->val, maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};
