// Leetcode problem link
// https://leetcode.com/problems/linked-list-random-node/

class Solution {
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    // Time Complexity O(n)
    // Space Complexity O(1)
    int getRandom() {
        // // Solution 1
        // int size = 0;
        // ListNode* temp = head;

        // while(temp)
        // {
        //     size++;
        //     temp = temp->next;
        // }

        // int random = rand() % size;
        // temp = head;

        // while(random--)
        //     temp = temp->next;

        // return temp->val;


        // Solution 2
        int random = rand();
        int size = 0;

        ListNode* temp = head;
        while(random--)
        {
            size++;
            temp = temp->next;
            if(temp == NULL)
            {
                temp = head;
                random %= size; 
            }
        }
        return temp->val;
    }
};
