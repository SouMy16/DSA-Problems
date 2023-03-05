class Solution {
public:
    int DFS(int pos, map<int, vector<int>> &m, int target, vector<int> vis, vector<int> &arr, vector<int> &dp)
    {
        if(pos == target) return 0;
        if(vis[pos] == 1) return 1+dp[pos];
        vis[pos] = 1;
        int ans = INT_MAX;
        if(pos>0 && vis[pos-1]==0) ans = min(ans, DFS(pos-1, m, target, vis, arr, dp));
        if(vis[pos+1]==0) ans = min(ans, DFS(pos+1, m, target, vis, arr, dp));
        for(int i=0; i<m[arr[pos]].size(); i++)
        {
            if(vis[m[arr[pos]][i]] == 0) ans = min(ans, DFS(m[arr[pos]][i], m, target, vis, arr, dp));
        }
        dp[pos] = ans;
        return dp[pos] == INT_MAX? dp[pos] : 1+dp[pos];
    }
    
    int BFS(int p, map<int, vector<int>> &m, int target, vector<int> vis, vector<int> &arr, vector<int> &dp)
    {
        queue<int> q;
        q.push(0);
        int ans = 0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                int pos = q.front();
                q.pop();
                vis[pos] = 1;
                if(pos == target) return ans;
                if(pos>0 && vis[pos-1]==0) 
                {
                    vis[pos-1] = 1;
                    q.push(pos-1);
                }
                if(vis[pos+1]==0) 
                {
                    vis[pos+1] = 1;
                    q.push(pos+1);
                }
                vector<int> nv;
                for(int i=0; i<m[arr[pos]].size(); i++) 
                {
                    if(vis[m[arr[pos]][i]] == 0) 
                    {
                        vis[m[arr[pos]][i]] = 1;
                        q.push(m[arr[pos]][i]);
                    }
                }
                m[arr[pos]] = nv;
            }
            ans++;
        }
        return ans;
    }
    
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> m;
        int n = arr.size();
        for(int i=0; i<n; i++)
        {
            m[arr[i]].push_back(i);
        }
        vector<int> vis(n,0);
        vector<int> dp(n, -1);
        int ans = BFS(0, m, n-1, vis, arr, dp);
        return ans;
    }
};