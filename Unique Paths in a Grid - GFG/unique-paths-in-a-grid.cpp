//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  long long int mod = 1000000007;
  int ans=0;
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        if(grid[0][0] == 0) return 0;
        vector<vector<long long int>> dp(n, vector<long long int> (m,0));
        dp[0][0] = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 0) continue;
                if(i-1>=0) dp[i][j] += dp[i-1][j];
                if(j-1>=0) dp[i][j] += dp[i][j-1];
                dp[i][j] = dp[i][j]%mod;
            }
        }
        return dp[n-1][m-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends