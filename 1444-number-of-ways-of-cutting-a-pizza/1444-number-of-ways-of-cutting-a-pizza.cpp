class Solution {
public:
    int mod = 1e9+7;
    int findWays(vector<string>& pizza, int k, int x, int y, vector<vector<vector<int>>>& dp)
    {
        if(dp[x][y][k] != -1) return dp[x][y][k];
        if(k == 0) 
        {
            for(int i=x; i<pizza.size(); i++)
            {
                for(int j=y; j<pizza[i].size(); j++)
                {
                    if(pizza[i][j] == 'A') return 1;
                }
            }
            return 0;
        }
        int xx=-1;
        int yy=-1;
        int f=0;
        for(int i=x; i<pizza.size(); i++) 
        {
            for(int j=y; j<pizza[i].size(); j++)
            {
                if(pizza[i][j] == 'A')
                {
                    xx=i;
                    yy=j;
                    f=1;
                    break;
                }
            }
            if(f) break;
        }
        if(f==0) 
        {
            dp[x][y][k] = 0;
            return 0;
        }
        long long int up = 0;
        for(int i=xx+1; i<pizza.size(); i++)
        {
            up += findWays(pizza, k-1, i, y, dp)%mod;
            up %= mod;
        }
        
        xx=-1;
        yy=-1;
        f=0;
        for(int i=y; i<pizza[0].size(); i++)
        {
            
            for(int j=x; j<pizza.size(); j++)
            {
                if(pizza[j][i]=='A')
                {
                    xx = j;
                    yy = i;
                    f=1;
                    break;
                }
            }
            if(f) break;
        }
        if(f==0) 
        {
            dp[x][y][k] = 0;
            return 0;
        }
        long long int left = 0;
        for(int i=yy+1; i<pizza[0].size(); i++)
        {
            left += findWays(pizza, k-1, x, i, dp)%mod;
            left %= mod;
        }
        
        long long int ans = up;
        ans += left;
        ans %= mod;
        dp[x][y][k] = ans;
        return ans;
    }
    
    int ways(vector<string>& pizza, int k) {
        vector<vector<vector<int>>> dp(pizza.size()+1, vector<vector<int>>(pizza[0].size()+1, vector<int>(k,-1)));
        int ans = findWays(pizza, k-1, 0, 0, dp);
        return ans%mod;
    }
};