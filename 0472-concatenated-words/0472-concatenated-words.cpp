class Solution {
public:
    bool isConcat(string word, map<string, int>& m, map<string, int> &dp)
    {
        if(m[word] == 1) return true;
        // cout<<word<<'\n';
        if(dp.find(word) != dp.end()) return dp[word]==1?true:false;
        string s = "";
        bool ans = false;
        for(int i=0; i<word.size(); i++)
        {
            s += word[i];
            if(m[s] == 1)
            {
                ans |= isConcat(word.substr(i+1), m, dp);
            }
        }
        if(m[s] == 1) ans = true;
        if(ans == true) dp[word] = 1;
        else dp[word] = 0;
        return ans;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        map<string, int> m;
        for(int i=0; i<n; i++) m[words[i]] = 1;
        map<string, int> dp;
        m[""] = 1;
        for(int i=0; i<n; i++)
        {
            m[words[i]] = 0;
            if(isConcat(words[i], m, dp)) ans.push_back(words[i]);
            m[words[i]] = 1;
        }
        return ans;
    }
};