class Solution {
public:
    void DFS(int pos, vector<int> &vis, vector<vector<int>> &g)
    {
        vis[pos] = 1;
        for(int i=0; i<g[pos].size(); i++)
        {
            if(!vis[g[pos][i]])
            {
                vis[g[pos][i]] = 1;
                DFS(g[pos][i], vis, g);
            }
        }
        return;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int> vis(n,0);
        int ans = -1;
        vector<vector<int>> g(n);
        for(int i=0; i<connections.size(); i++)
        {
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) 
            {
                ans++;
                DFS(i, vis, g);
            }
        }
        return ans;
    }
};