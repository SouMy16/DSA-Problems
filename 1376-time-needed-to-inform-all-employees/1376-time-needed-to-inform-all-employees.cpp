class Solution {
public:
    int height(int cur, vector<int> &manager, vector<int>& infoT, vector<int> &dp)
    {
        if(cur == -1) return 0;
        if(dp[cur] != -1) return dp[cur]; 
        return dp[cur] = infoT[cur] + height(manager[cur], manager, infoT, dp);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        vector<int> dp(n, -1); 
        for(int i=0; i<n; i++)
            ans = max(ans, height(i, manager, informTime, dp));
        return ans;
    }
};