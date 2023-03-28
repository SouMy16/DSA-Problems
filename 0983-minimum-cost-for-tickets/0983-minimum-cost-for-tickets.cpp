class Solution {
public:

    int solve(vector<int> &costs, vector<int>& days, int ind, int cur, vector<int> &dp)
    {
        if(ind >= days.size()) return cur;
        int ans = INT_MAX;
        if(dp[ind]!=-1) return cur+dp[ind];
        int i=0;
        
        // Choice 1
        while(ind+i<days.size() && days[ind+i]-days[ind]<1) i++;
        ans  = min(ans, solve(costs, days, ind+i, cur+costs[0], dp));
        
        // Choice 2
        while(ind+i<days.size() && days[ind+i]-days[ind]<7) i++;
        ans = min(ans, solve(costs, days, ind+i, cur+costs[1], dp));        
        
        // Choice 3
        while(ind+i<days.size() && days[ind+i]-days[ind]<30) i++;
        ans = min(ans, solve(costs, days, ind+i, cur+costs[2], dp));
        
        dp[ind] = ans-cur;
        return ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> year(366,0);
        vector<int> dp(n+1, -1);
        return solve(costs, days, 0, 0, dp);
        
        // vector<vector<int>> dp(n+1, vector<int>(4,-1));
        // dp[n-1][1] = costs[0];
        // for(int i=n-2; i>=0; i--)
        // {
        //     for(int j=3; j>=0; j--)
        //     {
        //         if(days[i+1]-days[i]<30) dp[i][3] = min(2*costs[0], costs[2]);
        //         if(days[i+1]-days[i]<7) dp[i][2] = costs[1];
        //         if(days[i+1])
        //     }
        // }
        
    }
};