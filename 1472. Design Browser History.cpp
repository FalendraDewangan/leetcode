// Leetcode problem link
// https://leetcode.com/problems/design-browser-history/

class node{
    public: 
    string val;
    node* prev;
    node* next;

    node(string str)
    {
        val = str;
        prev = next = NULL;
    }
};

class BrowserHistory {
    node* head;
public:
    BrowserHistory(string homepage) {
        head = new node(homepage);
    }
    
    void visit(string url) {
        
        node* temp = head->next;
        
        while(temp && temp->next)
        {
            temp = temp->next;
            delete temp->prev;
        }
        delete temp;

        head->next = new node(url);
        head->next->prev = head;
        head = head->next;
    }
    
    string back(int steps) {
        while(steps-- && head->prev)
            head = head->prev;

        return head->val;
    }
    
    string forward(int steps) {
        while(steps-- && head->next)
            head = head->next;
        
        return head->val;
    }
};
