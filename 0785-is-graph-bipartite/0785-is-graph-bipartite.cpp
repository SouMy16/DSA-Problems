class Solution {
public:
    bool dfs(vector<vector<int>> &graph, int p, vector<int> &vis, vector<int> &col)
    {
        if(vis[p]) return true;
        vis[p] = 1;
        bool ans = true;
        for(int i=0; i<graph[p].size(); i++)
        {
            if(col[graph[p][i]]==col[p]) return false;
            else if(!vis[graph[p][i]])
            {
                col[graph[p][i]] = 1^col[p];
                ans = (ans & dfs(graph, graph[p][i], vis, col));
            }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans = true;
        int n = graph.size();
        vector<int> color(n, -1);
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0) 
            {
                color[i] = 0;
                ans &= dfs(graph, i, vis, color);
            }
        }
        return ans;
    }
};