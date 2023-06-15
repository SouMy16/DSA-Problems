class Solution {
public:
    bool BFS(vector<vector<int>> &g, vector<int> &col, int n, int pos, vector<int> &vis)
    {
        queue<pair<int, int>> q;
        q.push({pos, 0});
        // vis[pos] = 1;
        // col[pos] = 0;
        while(!q.empty())
        {
            int cur = q.front().first;
            int c = q.front().second;
            q.pop();
            if(vis[cur]==1 && col[cur] != c) 
            {
                // cout<<cur<<" "<<col[cur]<<"\n";
                return false;
            }
            if(vis[cur] == 1) continue;
            col[cur] = c;
            vis[cur] = 1;
            for(int i=0; i<g[cur].size(); i++)  if(!vis[g[cur][i]]) q.push({g[cur][i], c^1});
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) if(!vis[i]) 
        {
            if(vis[i]==0 && !BFS(graph, col, n, i, vis)) 
            {
                return false;
            }
        }
        return true;
    }
};