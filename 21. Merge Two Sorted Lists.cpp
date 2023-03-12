// Leetcode Problem Link
// https://leetcode.com/problems/merge-two-sorted-lists/

// Time Complexity O(n)
// Space Complexity O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode *temp = new ListNode(-1);
        ListNode *ans = temp;
        
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<list2->val) 
            {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        
        if(list1!=NULL) temp->next=list1;
        if(list2!=NULL) temp->next=list2;
        
        return ans->next;
    }
};
