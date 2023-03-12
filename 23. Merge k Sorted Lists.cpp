// Leetcode problem link
// https://leetcode.com/problems/merge-k-sorted-lists/


// Solution 1
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

// Solution 2
class Solution {
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        if(l1->val <= l2->val)
        {
            l1->next = mergeTwoSortedList(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoSortedList(l1, l2->next);
            return l2;
        }
    }

    ListNode* mergeList(vector<ListNode*>& lists, int s, int e)
    {
        if(s==e)
            return lists[s];

        int mid = s + (e-s)/2;
        ListNode* l1 =  mergeList(lists, s, mid);
        ListNode* l2 = mergeList(lists, mid+1, e);

        return mergeTwoSortedList(l1, l2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0)
            return NULL;

        return mergeList(lists, 0, k-1);
    }
};

// Solution 3
class Solution {
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL)
            return l2;

        if(l2 == NULL)
            return l1;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                if(tail)
                {
                    tail->next = l1;
                    tail = tail->next;
                    l1 = l1->next;
                }
                else{
                    head = tail = l1;
                    l1 = l1->next;
                }
                
            }
            else
            {
                if(tail)
                {
                    tail->next = l2;
                    tail = tail->next;
                    l2 = l2->next;
                }
                else{
                    head = tail = l2;
                    l2 = l2->next;
                }
                
            }
        }

        if(l1)
            tail->next = l1;

        else if(l2)
            tail->next = l2;
        
        return head;
    }

    ListNode* mergeList(vector<ListNode*>& lists, int s, int e)
    {
        if(s==e)
            return lists[s];

        int mid = s + (e-s)/2;
        ListNode* l1 =  mergeList(lists, s, mid);
        ListNode* l2 = mergeList(lists, mid+1, e);

        return mergeTwoSortedList(l1, l2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0)
            return NULL;

        return mergeList(lists, 0, k-1);
    }
};
