//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        // Code here
        map<int,int> v;
        int mx=0;
        for(int i=0; i<n; i++)
        {
            v[intervals[i][0]]++;
            v[intervals[i][1]+1]--;
            mx = max(mx, intervals[i][1]);
        }
        int cur=0;
        int ans=-1;
        // for(int i=0; i<=mx+2; i++)
        // {
        //     cur += v[i];
        //     if(cur>=k)
        //     {
        //         ans = i;
        //     }
        // }
        int prev=0;
        for(auto it:v)
        {
            if(ans == prev) ans = it.first-1;
            cur += it.second;
            if(cur>=k)
            {
                ans = max(ans, it.first);
            }
            prev = it.first;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends