//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    long long int MOD = 1000000007;
	public:
	long long int solve(int ind, int arr[], int n, int sum, int cur, vector<vector<long long int>> &dp) {
	    if(cur>sum) return 0;
	    if(ind == n && cur == sum) return 1;
	    if(ind == n && cur != sum) return 0;
	    if(dp[ind][cur] != -1) return dp[ind][cur]%MOD;
	    long long int take = solve(ind+1, arr, n, sum, cur+arr[ind], dp)%MOD;
	    long long int nottake = solve(ind+1, arr, n, sum, cur, dp)%MOD;
	    dp[ind][cur] = (take%MOD+nottake%MOD)%MOD;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        sort(arr, arr+n);
        reverse(arr, arr+n);
        vector<vector<long long int>> dp(n+1, vector<long long int>(sum+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        // dp[1][arr[0]] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=sum; j++) {
                if(arr[i-1] <= j) {
                    dp[i][j] += dp[i-1][j-arr[i-1]]%MOD;
                }
                dp[i][j] += dp[i-1][j]%MOD;
            }
        }
        return dp[n][sum]%MOD;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends