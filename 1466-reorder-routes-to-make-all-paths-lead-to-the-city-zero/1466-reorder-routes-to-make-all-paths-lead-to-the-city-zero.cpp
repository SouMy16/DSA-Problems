class Solution {
public:
    void DFS(vector<vector<pair<int,int>>> &g, int pos, vector<int> &vis, int &ans)
    {
        vis[pos] = 1;
        for(int i=0; i<g[pos].size(); i++)
        {
            if(vis[g[pos][i].first]==0)
            {
                vis[g[pos][i].first] = 1;
                if(g[pos][i].second == 1) 
                {
                    ans = ans+1;
                    // cout<<"reverse "<<pos<<" to "<<g[pos][i].first<<'\n';
                }
                DFS(g, g[pos][i].first, vis, ans);
            }
        }
        return;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans = 0;
        vector<vector<pair<int,int>>> graph(n);
        vector<int> vis(n,0);
        for(int i=0; i<connections.size(); i++)
        {
            graph[connections[i][0]].push_back({connections[i][1],1});
            graph[connections[i][1]].push_back({connections[i][0],0});
        }
        DFS(graph, 0, vis, ans);
        // cout<<'\n';
        return ans;
    }
};