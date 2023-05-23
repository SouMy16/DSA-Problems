class Solution {
public:
    // int LPS(string &s, int st, int end, vector<vector<int>> &dp)
    // {
    //     if(st>end) return 0;
    //     if(s[st] == s[end]) return dp[st][end] = 1 + LPS(s, st+1, end-1, dp);
    //     LPS(s, st, end-1, dp);
    //     LPS(s, st+1, end, dp);
    //     return dp[st][end] = 0;
    // }
    
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0; i<n-1; i++)
        {
            // i is center
            for(int j=i, k=i; j>=0 && k<n; j--, k++)
            {
                if(s[j]!=s[k]) 
                {
                    if(k-j-1 > ans.size()) ans = s.substr(j+1, k-j-1);
                    break;
                }
                if(j==0 || k==n-1)
                {
                    if(k-j+1 > ans.size()) ans = s.substr(j, k-j+1);
                }
                // else if(k-j-1 > ans.size()) ans = s.substr(j, k-j+1);
            }
            
            // i and i+1 are center
            for(int j=i, k=i+1; j>=0 && k<n; j--, k++)
            {
                if(s[j]!=s[k]) 
                {
                    if(k-j-1>ans.size()) ans = s.substr(j+1, k-j-1);
                    break;
                }
                if(j==0 || k==n-1)
                {
                    if(k-j+1 > ans.size()) ans = s.substr(j, k-j+1);
                }
                // else if(k-j-1>ans.size()) ans = s.substr(j, k-j+1);
            }
        }
        if(ans.size() == 0) ans+=s[0];
        return ans;
    }
};