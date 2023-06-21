//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        vector<vector<int>> g(n);
        for(int i=0; i<m; i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, 0);
        vector<int> ans(n, -1);
        queue<int> q;
        q.push(src);
        int cur=-1;
        while(!q.empty())
        {
            cur++;
            int x=q.size();
            for(int i=0; i<x; i++)
            {
                int c=q.front();
                q.pop();
                ans[c] = cur;
                vis[c] = 1;
                for(int j=0; j<g[c].size(); j++)
                {
                    if(!vis[g[c][j]]) 
                    {
                        vis[g[c][j]] = 1;
                        q.push(g[c][j]);
                    }
                }
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends