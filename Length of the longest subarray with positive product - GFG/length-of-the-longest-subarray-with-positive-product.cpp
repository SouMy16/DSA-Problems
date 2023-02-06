//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        int maxLength(vector<int> &arr,int n){
           //code here
           int p = 1;
           int ans = 0;
           int cur = 0;
           int neg = -1;
           int fneg = -1;
           int start = 0;
           for(int i=0; i<n; i++)
           {
               if(arr[i] == 0)
               {
                   if(p > 0) ans = max(ans, i-start);
                   if(p < 0) 
                   {
                        ans = max(ans, i-1-fneg);
                        if(neg != -1) ans = max(ans, neg-start);
                        else ans = max(ans, fneg-start);
                   }
                   start = i+1;
                   p = 1;
                   neg = -1;
                   fneg = -1;
                   continue;
               }
               p *= arr[i]>0?1:-1;
               
               if(arr[i] < 0 && fneg == -1)
               {
                   fneg = i;
               }
               else if(arr[i] < 0 && fneg != -1) neg = i;
           }
           if(p > 0) ans = max(ans, n-start);
           if(p < 0) 
           {
                int i = n;
                ans = max(ans, i-1-fneg);
                if(neg != -1) ans = max(ans, neg-start);
                else ans = max(ans, fneg-start);
           }
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends