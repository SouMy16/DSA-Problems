class Solution {
    bool isloop = false;
public:
    void DFS(vector<vector<int>> &g, vector<vector<int>> &dp, vector<int> &vis, int pos, vector<int> &curvis)
    {
        if(curvis[pos] == 1)
        {
            isloop = true;
            return;
        }
        if(vis[pos] == 1) return;
        vis[pos] = 1;
        curvis[pos] = 1;
        vector<int> ans(26, 0);
        for(int i=0; i<g[pos].size(); i++)
        {
            if(curvis[g[pos][i]] == 1)
            {
                isloop = true;
                return;
            }
            DFS(g, dp, vis, g[pos][i], curvis);
            if(isloop == true) return;
            for(int j=0; j<26; j++) ans[j] = max(ans[j], dp[g[pos][i]][j]);
        }
        for(int i=0; i<26; i++) dp[pos][i] += ans[i];
        curvis[pos] = 0;
        return;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
       
        vector<vector<int>> g(colors.size());
        for(int i=0; i<edges.size(); i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<vector<int>> dp(colors.size(), vector<int> (26,0));
        for(int i=0; i<colors.size(); i++)
        {
            dp[i][colors[i]-'a']++;
        }
        
        vector<int> vis(colors.size(), 0);
        int ans = 0;
        vector<int> curvis(colors.size(), 0);
        for(int i=0; i<colors.size(); i++)
        {
            if(!vis[i]) 
            {
                DFS(g, dp, vis, i, curvis);
                int dpmax = 0;
                for(int j=0; j<26; j++) dpmax = max(dpmax, dp[i][j]);
                ans = max(ans, dpmax);
            }
        }
        if(isloop == true) return -1;
        return ans;
    }
    
    
    
    
//     void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, vector<bool> &track, vector<vector<int>> &colorMax, string &colors, int &ans, bool &isCycle) {
//         vis[node] = true;
        
//         for(int k: adj[node]) {
//             if (!vis[k]) {
//                 dfs(k, vis, adj, track, colorMax, colors, ans, isCycle);
//             } else if (!track[k]) isCycle = true;
//             for(int it=0;it<26;it++) {
//                 colorMax[node][it] = max(colorMax[node][it], colorMax[k][it]);
//             }
//         }
        
//         colorMax[node][colors[node] - 'a'] += 1;
//         ans = max(ans, colorMax[node][colors[node] - 'a']);
//         track[node] = true;
//     }
//     int largestPathValue(string colors, vector<vector<int>>& edges) {
//         int n = colors.length();
//         vector<bool> track(n, false);
//         vector<bool> vis(n, false);
//         bool isCycle = false;
//         vector<vector<int>> adj(n);
//         vector<vector<int>> colorMax(n, vector<int> (26, 0));
//         int ans = 1;

//         for(int i=0;i<edges.size();i++) {
//             adj[edges[i][0]].push_back(edges[i][1]);
//         }

//         for(int i=0;i<n;i++) {
//             if (!vis[i]) {
//                 dfs(i, vis, adj, track, colorMax, colors, ans, isCycle);
//             }
//         }

//         if (isCycle) return -1;
//         return ans;
//     }
};