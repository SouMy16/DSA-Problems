class Solution {
    
public:
    int LCS(string s, string r, vector<vector<int>> &mp)
    {
        int n = s.size();
        int m = r.size();
        if(n==0 || m==0) return 0;
        if(mp[n][m]!=-1) return mp[n][m];
        if(s[n-1] == r[m-1])
        {
            s.pop_back();
            r.pop_back();
            mp[n][m] = 1+LCS(s, r, mp);
        }
        else 
        {
            char x = s.back();
            s.pop_back();
            mp[n][m] = LCS(s, r, mp);
            s.push_back(x);
            r.pop_back();
            mp[n][m] = max(mp[n][m], LCS(s, r, mp));
        }
        
        return mp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        int n = s.size();
        vector<vector<int>> mp(n+1, vector<int>(n+1,0));
        // int ans = LCS(s,r,mp);
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1] == r[j-1])
                {
                    mp[i][j] = 1+mp[i-1][j-1];
                }
                else mp[i][j] = max(mp[i][j-1], mp[i-1][j]);
                ans = max(mp[i][j], ans);
            }
        }
        return ans;
    }
};