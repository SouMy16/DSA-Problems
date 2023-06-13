//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void DFS(vector<vector<int>> &adj, int pos, vector<int> &vis)
    {
        vis[pos] = 1;
        for(int i=0; i<adj[pos].size(); i++)
        {
            if(adj[pos][i] && !vis[i]) DFS(adj, i, vis);
        }
        return;
    }
    
    int numProvinces(vector<vector<int>> adj, int n) {
        // code here
        int ans = 0;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) 
        {
            if(!vis[i]) 
            {
                ans++;
                DFS(adj, i, vis);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends