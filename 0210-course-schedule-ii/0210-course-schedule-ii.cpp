class Solution {
public:
    bool detectCycle(vector<vector<int>> &g, int pos, vector<int> &vis, vector<int> &curvis)
    {
        bool ans = false;
        int n = g.size();
        if(curvis[pos]) return true;
        if(vis[pos]) return false;
        vis[pos] = 1;
        curvis[pos] = 1;
        for(int i=0; i<g[pos].size(); i++)
        {
            if(detectCycle(g, g[pos][i], vis, curvis)) return true;
        }
        curvis[pos] = 0;
        return false;
    }
    
    void TopoSort(vector<vector<int>> &g, vector<int> &ans)
    {
        queue<int> q;
        int n = g.size();
        vector<int> in(n, 0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<g[i].size(); j++)
            {
                in[g[i][j]]++;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(in[i] == 0) q.push(i);
        }
        map<int,int> m;
        while(!q.empty())
        {
            int cur = q.front(); 
            q.pop();
            ans.push_back(cur);
            for(int i=0; i<g[cur].size(); i++) 
            {
                in[g[cur][i]]--;
                if(in[g[cur][i]] == 0) 
                {
                    q.push(g[cur][i]);
                    
                }
            }
        }
        return;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<int> vis(n, 0);
        vector<int> curvis(n, 0);
        vector<vector<int>> g(n);
        for(int i=0; i<pre.size(); i++) g[pre[i][1]].push_back(pre[i][0]);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                if(detectCycle(g, i, vis, curvis)) return ans;
            }
        }
        TopoSort(g, ans);
        // cout<<"No Cycle";
        return ans;
    }
};