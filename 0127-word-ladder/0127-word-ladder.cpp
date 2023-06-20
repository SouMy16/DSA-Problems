class Solution {
public:
    // int findAns(string s, string &t, map<string, int> &m, map<string, int> &dp, map<string, int> &vis)
    // {
    //     if(s == t) return 1;
    //     if(dp.find(s) != dp.end()) return dp[s];
    //     string c = s;
    //     int ans = 100000;
    //     // vis[s] = 1;
    //     for(int i=0; i<s.size(); i++)
    //     {
    //         for(int j=0; j<26; j++)
    //         {
    //             if('a'+j != s[i]) c[i] = 'a'+j;
    //             if(!vis[c] && m[c] == 1) 
    //             {
    //                 vis[c] = 1;
    //                 ans = min(ans, 1 + findAns(c, t, m, dp, vis));
    //                 vis[c] = 0;
    //             }
    //         }
    //         c[i] = s[i];
    //     }
    //     // vis[s] = 0;
    //     return dp[s] = ans;
    // }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> m, vis;
        int ans = 0;
        for(int i=0; i<wordList.size(); i++) m[wordList[i]]=1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty())
        {
            ans++;
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                string cur = q.front();
                if(cur == endWord) return ans;
                for(int k=0; k<cur.size(); k++)
                {
                    for(int j=0; j<26; j++)
                    {
                        cur[k] = 'a'+j;
                        if(!vis[cur] && m[cur]==1) 
                        {
                            vis[cur] = 1;
                            q.push(cur);
                        }
                    }
                    cur = q.front();
                }
                q.pop();
            }
        }
        return 0;
    }
};