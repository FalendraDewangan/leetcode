// Leetcode problem link
// https://leetcode.com/problems/merge-k-sorted-lists/

// Time complexity : O(nlogk)
// pace complexity : O(k)

class comparator{
    public:
    bool operator() (ListNode*& a, ListNode*& b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparator> pq;

        for(ListNode* & node : lists)
        {
            if(node)
                pq.push(node);
        }
            

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty())
        {
            if(!head)
            {
                head = tail = pq.top();
                pq.pop();
            }
            else{
                tail->next = pq.top();
                tail = tail->next;
                pq.pop();
            }

            if(tail->next)
                pq.push(tail->next);
        }
        return head;
    }
};
