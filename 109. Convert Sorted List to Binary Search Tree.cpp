// Leetcode Problem link
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/


//     Time complexity:
//     Solution1 : O(n^2)
//     Solution2 : O(n)

//     Space complexity:
//     Solution1 : O(logn)
//     Solution2 : O(n)


class Solution {

    TreeNode* solution1(ListNode* head)
    {
        if(head==NULL)
            return NULL;

        ListNode* mid = getMid(head);

        TreeNode* root = new TreeNode(mid->val);
        if(head != mid)
            root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }

    ListNode* getMid(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev)
            prev->next = NULL;
        
        return slow;
    }
    
    TreeNode* solution2(ListNode* head)
    {
        vector<int> nums;
        listToTree(head, nums);
        return formTree(nums, 0, nums.size()-1);
    }

    void listToTree(ListNode* head, vector<int>& arr)
    {
        while(head)
        {
            arr.push_back(head->val);
            head = head->next;
        }
    }

    TreeNode* formTree(vector<int>& nums, int s, int e)
    {
        if( s > e)
            return NULL;
        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = formTree(nums, s, mid-1);
        root->right = formTree(nums, mid+1, e);

        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // return solution1(head);
        return solution2(head);
    }
};
