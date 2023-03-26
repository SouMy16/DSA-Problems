class Solution {
public:
    void loop(vector<int>& edges, int pos, unordered_map<int,int>& m, vector<int> &vis, int &ans)
    {
        vis[pos] = 1;
        if(edges[pos] == -1) return;
        if(vis[edges[pos]] == 0 && m[edges[pos]] == 0)
        {
            m[edges[pos]] = m[pos] + 1;
            loop(edges, edges[pos], m, vis, ans);
            return;
        }
        if(vis[edges[pos]] == 1 && m[edges[pos]]!=0) ans = max(ans, m[pos]-m[edges[pos]]+1);
        return;
    }
    
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        vector<int> vis(edges.size(),0);
        for(int i=0; i<edges.size(); i++)
        {
            if(!vis[i])
            {
                unordered_map<int,int> m;
                m[i] = 1;
                loop(edges, i, m, vis, ans);
            }
        }
        return ans;
    }
    
};