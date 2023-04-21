class Solution {
public:
    int mod = 1e9+7;
    int solve(vector<int> &group, vector<int> &profit, int ind, int curp, int members, int minp, vector<vector<vector<int>>> &dp)
    {
        if(ind == group.size())
        {
            if(curp >= minp) return 1;
            return 0;
        }
        if(dp[ind][curp][members] != -1) return dp[ind][curp][members]%mod;
        int op1 = 0, op2 = 0;
        if(members >= group[ind]) op1 = solve(group, profit, ind+1, curp+profit[ind], members-group[ind], minp, dp)%mod;
        op2 = solve(group, profit, ind+1, curp, members, minp, dp)%mod;
        dp[ind][curp][members] = (op1%mod+op2%mod)%mod;
        return dp[ind][curp][members]%mod;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // memset(dp, -1, sizeof(dp));
        int sum = 0;
        for(int i=0; i<profit.size(); i++) sum += profit[i];
        vector<vector<vector<int>>> dp(group.size()+1, vector<vector<int>> (sum+1, vector<int>(n+1, -1)));
        int ans = solve(group, profit, 0, 0, n, minProfit, dp)%mod;
        return ans;
    }
};