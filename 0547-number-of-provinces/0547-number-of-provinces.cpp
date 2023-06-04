class Solution {
public:
    void traverse(int pos, vector<vector<int>> &g, vector<int> &vis)
    {
        if(vis[pos] == 1) return;
        vis[pos] = 1;
        for(int i=0; i<g[pos].size(); i++)
        {
            if(i!=pos && g[pos][i] == 1) traverse(i, g, vis);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++)
        {
            if(vis[i] == 0)
            {
                ans++;
                // cout<<i<<" ";
                traverse(i, isConnected, vis);
            }
        }
        return ans;
    }
};