//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solve(int coins[], int amount, vector<vector<long long int>> &dp, int ind, int n){
        if(amount == 0) return 1LL*1;
        if(ind >= n) return 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        long long int x = 0;
        if(amount>=coins[ind]) x += solve(coins, amount-coins[ind], dp, ind, n);
        x += solve(coins, amount, dp, ind+1, n);
        return dp[ind][amount] = x;
    }
    
    long long int count(int coins[], int N, int sum) {
        // code here.
        vector<vector<long long int>> dp(N+1, vector<long long int>(sum+1, 0));
        // return solve(coins, sum, dp, 0, N);
        
        for(int i=0; i<=N; i++) dp[i][0] = 1;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=sum; j++){
                if(j >= coins[i-1]) dp[i][j] += dp[i][j-coins[i-1]];
                dp[i][j] += dp[i-1][j];
            }
        }
        return dp[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends