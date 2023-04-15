class Solution {
public:
    
    int solve(vector<vector<int>> &piles, int i, int j, int k, vector<vector<vector<int>>> &dp)
    {
        if(k==0) 
        {
            return 0;
        }
        if(i==piles.size()) return INT_MIN;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int take = 0;
        if(j<piles[i].size()) take = solve(piles, i, j+1, k-1, dp)+piles[i][j];
        int nottake = solve(piles, i+1, 0, k, dp);
        dp[i][j][k] = max(take, nottake);
        return dp[i][j][k];
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int mx = 0;
        for(int i=0; i<piles.size(); i++) mx = max(mx, (int)piles[i].size());
        vector<vector<vector<int>>> dp(piles.size()+1, vector<vector<int>>(mx+1, vector<int>(k+1, -1)));
        return solve(piles, 0, 0, k, dp);
    }
};