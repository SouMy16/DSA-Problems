class Solution {
public:
    int dp[501][501];
    int solve(string &str, int s, int e)
    {
        if(s>=e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        if(str[s] == str[e]) return solve(str, s+1, e-1);
        return dp[s][e] = 1+min(solve(str, s, e-1), solve(str, s+1, e));
    }
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.size()-1);
    }
};