//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int arr[], int n, int ind, int &ans, vector<int> &dp)
    {
        if(ind >= n) return 0;
        if(dp[ind] != -1) return dp[ind];
        int take = arr[ind] + solve(arr, n, ind+2, ans, dp);
        int nottake = solve(arr, n, ind+1, ans, dp);
        return dp[ind] = max(take, nottake);
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // int ans = 0;
        // vector<int> dp(n, -1);
        // return solve(arr, n, 0, ans, dp);
        int takethis = 0, nottakethis = 0, nottakeprev = 0;
        for(int i=0; i<n; i++)
        {
            nottakethis = max(nottakeprev, takethis);
            takethis = nottakeprev + arr[i];
            nottakeprev = nottakethis;
        }
        return max(takethis, nottakethis);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends