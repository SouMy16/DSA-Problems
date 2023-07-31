//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            vis[cur] = 1;
            for(int i=0; i<adj[cur].size(); i++)
            {
                if(vis[adj[cur][i]] == 0) 
                {
                    vis[adj[cur][i]] = 1;
                    q.push(adj[cur][i]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends