struct Node{
    Node* a[26];
    bool flag = false;
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
        for(int i=0; i<26; i++)
        {
            root->a[i] = NULL;
        }
    }
    
    void insert(string word) {
        Node* cur = root;
        for(int i=0; i<word.size(); i++)
        {
            if(cur->a[word[i]-'a'] == NULL)
            {
                cur->a[word[i]-'a'] = new Node();
                for(int j=0; j<26; j++)
                {
                    cur->a[word[i]-'a']->a[j] = NULL;
                }
            }
            cur = cur->a[word[i]-'a'];
        }
        cur->flag = true;
        return;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(int i=0; i<word.size(); i++)
        {
            if(cur->a[word[i]-'a'] == NULL)
            {
                return false;
            }
            cur = cur->a[word[i]-'a'];
        }
        if(cur->flag != true) return false;
        return true;
    }
    
    bool startsWith(string word) {
        Node* cur = root;
        for(int i=0; i<word.size(); i++)
        {
            if(cur->a[word[i]-'a'] == NULL)
            {
                return false;
            }
            cur = cur->a[word[i]-'a'];
        }
        // if(flag[cur] != true) return false;
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */