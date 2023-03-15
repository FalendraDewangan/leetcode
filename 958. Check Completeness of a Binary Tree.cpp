// Leetcode Problem link
// https://leetcode.com/problems/check-completeness-of-a-binary-tree/

// Solution 1 : BFS APPROACH
// O(N) Time Complexity
// O(N) Space Complexity

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool pastNull = false;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode * front = q.front();
            q.pop();

            if(pastNull && front)
                return false;

            if(!front)
            {
                pastNull = true;
                continue;
            }
            else
            {
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};

// Solution 2 : DFS APPROACH
// O(N) Time Complexity
// O(N) Space Complexity
class Solution {
    int countNodes(TreeNode* root)
    {
        if(!root)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool valid(TreeNode* root, int i, int& totalNodes)
    {
        if(!root)
            return true;

        if(i > totalNodes)
            return false;
        
        return valid(root->left, 2*i, totalNodes) && valid(root->right, 2*i+1, totalNodes);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);

        return valid(root, 1, totalNodes);
    }
};
