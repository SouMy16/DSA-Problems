class Solution {
public:
    int MOD=1000000007;
    int solve(vector<int>& a, int s, int e, int fuel, vector<vector<int>> &dp)
    {
        // if(s == e) 
        if(fuel < 0) return 0;
        if(dp[s][fuel] != -1) 
        {
            // cout<<"r1 ";
            return dp[s][fuel];
        }
        int ans = 0;
        if(s == e) 
        {
            // cout<<"1 ";
            ans = 1;
        }
        for(int i=0; i<a.size(); i++)
        {
            if(i != s)
            {
                // if(fuel >= abs(a[i]-a[s]) && i==e) ans += 1+solve(a, i, e, fuel-abs(a[i]-a[s]), ans, dp);
                if(fuel >= abs(a[i]-a[s])) ans = (ans+solve(a, i, e, fuel-abs(a[i]-a[s]), dp)%MOD)%MOD;
            }
        }
        // if(s==e) return dp[s][fuel] = 1+ans;
        // cout<<"r2 ";
        return dp[s][fuel] = ans;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int ans = 0;
        vector<vector<int>> dp(locations.size()+1, vector<int>(fuel+1, -1));
        solve(locations, start, finish, fuel, dp);
        return dp[start][fuel];
    }
};