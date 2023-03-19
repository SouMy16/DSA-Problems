struct Node{
    bool flag = false;
    Node* a[26];
};

class WordDictionary {
public:
    Node* head;
    map<string,int> m;
    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        Node* cur = head;
        for(int i=0; i<word.size(); i++)
        {
            if(cur->a[word[i]-'a'] == NULL)
            {
                cur->a[word[i]-'a'] = new Node();
                for(int j=0; j<26; j++) cur->a[word[i]-'a']->a[j] = NULL;
            }
            cur = cur->a[word[i]-'a'];
        }
        cur->flag = true;
        return;
    }
    
    bool search(string word, Node* cur)
    {
        for(int i=0; i<word.size(); i++)
        {
            if(word[i] == '.')
            {
                bool ans = false;
                for(int j=0; j<26; j++)
                {
                    if(cur->a[j] != NULL)
                    {
                        ans = ans | search(word.substr(i+1), cur->a[j]);
                    }
                }
                return ans;
            }
            else if(cur->a[word[i]-'a'] == NULL) return false;
            else cur = cur->a[word[i]-'a'];
        }
        if(cur->flag) return true;
        return false;
    }
    
    bool search(string word) {
        Node* cur = head;
        for(int i=0; i<word.size(); i++)
        {
            if(word[i] == '.')
            {
                bool ans = false;
                for(int j=0; j<26; j++)
                {
                    if(cur->a[j] != NULL)
                    {
                        ans = ans | search(word.substr(i+1), cur->a[j]);
                    }
                }
                return ans;
            }
            else if(cur->a[word[i]-'a'] == NULL) return false;
            else cur = cur->a[word[i]-'a'];
        }
        if(cur->flag) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */