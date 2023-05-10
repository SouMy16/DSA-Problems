//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int K,vector<int> &A){
        // Code here
        vector<int> mx, mn;
        // int n = A.size();
        int pre = A[0];
        for(int i=0; i<n; i++)
        {
            pre = max(pre, A[i]);
            mx.push_back(pre);
        }
        pre = A[n-1];
        for(int i=n-2; i>=0; i--)
        {
            mn.push_back(pre);
            pre = min(pre, A[i]);
        }
        int ans = 0;
        for(int i=0; i<n-1; i++)
        {
            if(mx[i]+mn[n-2-i]>=K) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends