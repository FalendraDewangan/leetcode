// Leetcode Problem link
// https://leetcode.com/problems/construct-string-from-binary-tree/

class Solution {
public:
    string tree2str(TreeNode* root) {
        if(!root)
            return "";
        string str = to_string(root->val);

        if(root->left == NULL && root->right == NULL)
            return to_string(root->val);

        str += "(" + tree2str(root->left) + ")" ;

        if(root->right)
            str += "(" + tree2str(root->right) + ")";

        return str;
    }
};
