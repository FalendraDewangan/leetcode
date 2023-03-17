// Leetcode problem link
// https://leetcode.com/problems/implement-trie-prefix-tree/

class node{
    public: 
    char ch;
    node* next[26];
    bool end;
    node(char c)
    {
        ch = c;
        for(int i=0; i<26; i++)
            next[i] = NULL;
        end = false;
    }
};

class Trie {
    node* root;
public:
    Trie() {
        root = new node('/');
    }
    
    void insert(string word) {
        node* temp = root;
        for(char& ch : word)
        {
            if(!temp->next[ch-'a'])
                temp->next[ch-'a'] = new node(ch);
            temp = temp->next[ch-'a'];
        }

        temp->end = true;
    }
    
    bool search(string word) {
        node* temp = root;

        for(int i=0; temp && i<word.size(); i++)
            temp = temp->next[word[i] - 'a'];
        
        return temp ? temp->end : false;
    }
    
    bool startsWith(string prefix) {
        node* temp = root;

        for(int i=0; temp && i<prefix.size(); i++)
            temp = temp->next[prefix[i] - 'a'];
        
        return temp ? true : false;
    }
};
