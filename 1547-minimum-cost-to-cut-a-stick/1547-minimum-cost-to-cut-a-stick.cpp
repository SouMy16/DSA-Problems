class Solution {
public:
    
    int solve(int x, int y, int s, int e, vector<int> &cuts, vector<vector<int>>& dp)
    {
        if(s>=e) return 0;
        if(dp[s][e] != -1) return dp[s][e];
        int mn = INT_MAX;
        for(int i=s; i<e; i++)
        {
            // vector<int> left, right;
            // for(int j=0; j<i; j++) left.push_back(cuts[j]);
            // for(int j=i+1; j<cuts.size(); j++) right.push_back(cuts[j]);
            int cut = cuts[i];
            mn = min(mn, solve(x, cut, s, i, cuts, dp)+solve(cut, y, i+1, e, cuts, dp));
        }
        return dp[s][e] = y - x + mn;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int ans = 0;
        int cost = 0;
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size()+1, vector<int>(cuts.size()+1, -1));
        return solve(0, n, 0, cuts.size(), cuts, dp);
    }
};