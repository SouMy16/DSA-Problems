//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    // int solve(int n, int cur) {
    //     if(n == cur) return 0;
    //     int op1 = 1+solve(n, cur+1);
    //     int op2 = 1+solve(n, 2*cur);
    //     return min(op1, op2);
    // }
    int minOperation(int n)
    {
        // int ans = 0;
        // return 1+solve(n, 1);
        int ans = 0;
        while(n) {
            if(n%2) ans++, n--;
            else ans++, n/=2;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends