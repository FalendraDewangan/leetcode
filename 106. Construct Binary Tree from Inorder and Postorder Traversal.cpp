// Leetcod problem link
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


// Solution 1 
//     Time complexity : O(n^2)
//     Space complexity : O(n)

class Solution {
    int findIndex(vector<int>& inorder, int val)
    {
        for(int i=0; i<inorder.size(); i++)
        {
            if(inorder[i] == val)
                return i;
        }
        return -1;
    }

    TreeNode* solveRec(vector<int>& inorder, vector<int>& postorder, int s, int e, int& rootIndex)
    {
        if(s > e)
            return NULL;

        --rootIndex;
        TreeNode* root = new TreeNode(postorder[rootIndex]);
        int index = findIndex(inorder, postorder[rootIndex]);

        root->right = solveRec(inorder, postorder, index+1, e, rootIndex);
        root->left = solveRec(inorder, postorder, s, index-1, rootIndex);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIndex = inorder.size();
        return solveRec(inorder, postorder, 0, inorder.size()-1, rootIndex);
    }
};



// Solution 2 : Optimal solution
//     Time complexity : O(n)
//     Space complexity : O(n)


class Solution {
    TreeNode* solveRec(vector<int>& inorder, vector<int>& postorder, int s, int e, int& rootIndex, unordered_map<int, int>& index)
        {
            if(s > e)
                return NULL;

            --rootIndex;
            TreeNode* root = new TreeNode(postorder[rootIndex]);
            int ind = index[postorder[rootIndex]];

            root->right = solveRec(inorder, postorder, ind+1, e, rootIndex, index);
            root->left = solveRec(inorder, postorder, s, ind-1, rootIndex, index);

            return root;
        }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIndex = inorder.size();
        unordered_map<int, int> index;

        for(int i=0; i<inorder.size(); i++)
            index[inorder[i]] = i;

        return solveRec(inorder, postorder, 0, inorder.size()-1, rootIndex, index);
    }
};
