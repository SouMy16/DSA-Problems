class Solution {
public:
    int solve(vector<int>& a, int fee, int ind, int b, vector<vector<int>> &dp)
    {
        if(ind == a.size()) 
        {
            return 0;
        }
        
        if(b == -1) 
        {
            if(dp[ind][0] != -1) return dp[ind][0];
            int notBuy, buy;
            notBuy = solve(a, fee, ind+1, -1, dp);
            buy = -a[ind]+solve(a, fee, ind+1, 0, dp);
            return dp[ind][0] = max(buy, notBuy);
        }
        
        if(dp[ind][1] != -1) return dp[ind][1];
        int sell, notSell;
        sell = a[ind]-fee+solve(a, fee, ind+1, -1, dp);
        notSell = solve(a, fee, ind+1, 0, dp);
        return dp[ind][1] = max(sell, notSell);
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
        // unordered_map<int, map<int,int>> m;
        // int i0=0, i1=0;
        // for(int i=prices.size()-1; i>=0; i--)
        // {
        //     i0 = max(i0, i1-prices[i]);
        //     i1 = max(i1, i0+prices[i]-fee);
        // }
        // return i0;
        // return solve(prices, fee, 0, -1, dp);
        int s0 = 0, s1 = INT_MIN; 
        for(int p:prices) {
            int tmp = s0;
            s0 = max(s0, s1+p);
            s1 = max(s1, tmp-p-fee);
        }
        return s0;
    }
};