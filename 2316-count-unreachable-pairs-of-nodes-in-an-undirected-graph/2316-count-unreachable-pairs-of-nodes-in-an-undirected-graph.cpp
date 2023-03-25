class Solution {
public:
    long long int DFS(int pos, vector<vector<int>> &g, vector<int> &vis)
    {
        long long int ans = 1;
        vis[pos] = 1;
        for(int i=0; i<g[pos].size(); i++)
        {
            if(!vis[g[pos][i]])
            {
                vis[g[pos][i]] = 1;
                ans += DFS(g[pos][i], g, vis);
            }
        }
        return ans;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long int ans = 0;
        vector<vector<int>> graph(n);
        for(int i=0; i<edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        long long int nodes = 0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                long long int x = DFS(i, graph, vis);
                ans += nodes*x;
                nodes += x;
            }
        }
        return ans;
    }
};