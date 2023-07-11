class TrieNode {
    private:
    public:
        vector<TrieNode*> a;
        bool end;
        TrieNode() {
            a.resize(26, NULL);
            end = false;
        }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(int i=0; i<word.size(); i++)
        {
            if(cur->a[word[i]-'a']==NULL)
            {
                cur->a[word[i]-'a'] = new TrieNode();
            }
            cur = cur->a[word[i]-'a'];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(int i=0; i<word.size(); i++)
        {
            if(cur->a[word[i]-'a']==NULL)
            {
                return false;
            }
            cur = cur->a[word[i]-'a'];
        }
        return cur->end == true;
    }
    
    bool startsWith(string word) {
        TrieNode* cur = root;
        for(int i=0; i<word.size(); i++)
        {
            if(cur->a[word[i]-'a']==NULL)
            {
                return false;
            }
            cur = cur->a[word[i]-'a'];
        }
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