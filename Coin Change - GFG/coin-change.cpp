//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int S[], int m, int n) 
    {
        // code here.
        vector<vector<long long int>> dp(m,vector<long long int>(n+1,0));
        // long long int ans = Coins(S,dp,m-1,n);
        for(int i=0;i<m;i++) dp[i][0]=1;
        
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(S[i]<=j){
                    dp[i][j]+=(dp[i][j-S[i]]);
                }
                // else{
                    if(i>0) dp[i][j]+=dp[i-1][j];
                // }
            }
        }
        return dp[m-1][n];;
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