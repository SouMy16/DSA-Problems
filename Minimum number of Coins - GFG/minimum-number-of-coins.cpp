//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(2, INT_MAX));
        // dp[1] = 1;
        // dp[2] = 1;
        // dp[5] = 1;
        // dp[10] = 1;
        // dp[20] = 1;
        // dp[50] = 1;
        // dp[100] = 1;
        // dp[200] = 1;
        // dp[500] = 1;
        // dp[2000] = 1;
        dp[0][0] = 0;
        dp[0][1] = 0;
        int coins[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        for(int i=1; i<=n; i++)
        {
            int cur = dp[i][0];
            for(int j=0; j<10; j++)
            {
                if(coins[j] > i) break;
                if(cur>dp[i-coins[j]][0]+1)
                {
                    cur = dp[i-coins[j]][0]+1;
                    dp[i][1] = coins[j];
                }
            }
            dp[i][0] = cur;
        }
        // dp[n][1] = 20;
        // cout<<dp[n]<<'\n';
        vector<int> ans;
        int cur = n;
        while(cur > 0)
        {
            ans.push_back(dp[cur][1]);
            cur -= dp[cur][1];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends