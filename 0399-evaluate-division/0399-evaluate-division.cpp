class Solution {
public:
    double dfs(string a, string c, unordered_map<string, vector<pair<string, double>>> &g, unordered_map<string, int> &vis)
    {
        if(a == c) return 1.0;
        double ans = 0;
        vis[a] = 1;
        for(auto e:g[a])
        {
            double v = e.second;
            string b = e.first;
            if(vis[b] == 0)
            {
                vis[b] = 1;
                double cur = dfs(b, c, g, vis);
                if(cur > 0)
                {
                    return cur * v;
                }
            }
        }
        return 0;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = queries.size();
        vector<double> ans(n);
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i=0; i<equations.size(); i++)
        {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            double d = 1.0/values[i];
            // cout<<d<<" ";
            graph[equations[i][1]].push_back({equations[i][0], d});
        }
        for(int i=0; i<queries.size(); i++)
        {
            string a = queries[i][0], c = queries[i][1];
            // int n = graph.size();
            unordered_map<string, int> vis;
            if(graph[a].size()==0 || graph[c].size()==0)
            {
                ans[i] = -1;
                continue;
            }
            double cur = dfs(a, c, graph, vis);
            ans[i] = cur;
            if(ans[i] == 0) ans[i] = -1;
        }
        return ans;
    }
};