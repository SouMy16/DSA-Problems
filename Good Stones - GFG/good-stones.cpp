//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:

    int goMove(vector<int> &arr, int pos, vector<int> &vis, int n, vector<int> & good, map<int,int> &m)
    {
        if(pos<0 || pos>=n) return 1;
        if((vis[pos] == 1 && good[pos] == -1) || m[pos] == 1)
        {
            return -1;
        }
        if(vis[pos] == 1 && good[pos] == 1) return 1;
        m[pos] = 1;
        return goMove(arr, pos+arr[pos], vis, n, good, m);
    }

    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int> vis(n,0);
        vector<int> good(n,0);
        for(int i=0; i<n; i++)
        {
            if(vis[i] == 0)
            {
                map<int,int> m;
                int x = goMove(arr, i, vis, n, good, m);
                if(x == -1)
                {
                    for(map<int,int>::iterator it = m.begin(); it!=m.end(); it++)
                    {
                        vis[it->first] = 1;
                        good[it->first] = -1;
                    }
                }
                else{
                    for(map<int,int>::iterator it = m.begin(); it!=m.end(); it++)
                    {
                        vis[it->first] = 1;
                        good[it->first] = 1;
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) 
        {
            // cout<<good[i]<<'\n';
            ans += good[i]==1?1:0;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends