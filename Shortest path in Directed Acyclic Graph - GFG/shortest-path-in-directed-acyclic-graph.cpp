//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<int> ans(n, -1);
        vector<vector<pair<int,int>>> g(n);
        for(int i=0; i<m; i++) g[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        queue<pair<int, int>> q;
        q.push({0, 0});
        // vector<int> vis(n, 0);
        while(!q.empty())
        {
            int cur = q.front().first;
            int cost = q.front().second;
            q.pop();
            if(ans[cur] == -1) ans[cur] = cost;
            else if(ans[cur] <= cost) continue;
            else ans[cur] = cost;
            for(int i=0; i<g[cur].size(); i++)
            {
                q.push({g[cur][i].first, g[cur][i].second+cost});
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends