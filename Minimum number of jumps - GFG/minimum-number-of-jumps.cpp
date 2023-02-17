//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int mx = 0;
        int curmx = 0;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            mx = max(mx, i+arr[i]);
            if(i == curmx)
            {
                ans++;
                curmx = mx;
                if(curmx == n-1) return ans;
            }
            if(i > curmx) return -1;
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
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends