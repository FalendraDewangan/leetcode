// Leetcode problem link
// https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && (slow != fast))
        {
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
        }

        if(slow != fast)
            return NULL;

        slow = head;
        fast = fast->next;

        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
