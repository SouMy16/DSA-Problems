class Solution {
public:
    bool DFS(int i, vector<vector<int>> &g, vector<int> &vis, vector<int> &dp)
    {
        // if(m[i]) return true;
        if(dp[i] != -1) return dp[i] == 1;
        bool ans = true;
        dp[i] = 0;
        for(int j=0; j<g[i].size(); j++)
        {
            ans &= DFS(g[i][j], g, vis, dp);
        }
        return dp[i] = (ans==true);
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> dp(n, -1), vis(n, 0);
        for(int i=0; i<n; i++) 
        {
            if(graph[i].size() == 0) 
            {
                dp[i] = 1;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(DFS(i, graph, vis, dp)) ans.push_back(i);
        }
        return ans;
    }
};