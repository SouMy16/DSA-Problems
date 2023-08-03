//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dfs(int i, int j, int x, int y, vector<vector<int>> &a, int n, int m, vector<vector<int>> &vis,vector<vector<int>> &dp)
    {
        if(i<0 || j<0 || i>=n || j>=m) return 1e6;
        if(a[i][j] == 0) return 1e6;
        if(i==x && j==y && a[i][j]==1) return 0;
        if(vis[i][j]) return 1e6;
        // if(dp[i][j] != -1) return dp[i][j];
        int ans;
        vis[i][j] = 1;
        int up    = dfs(i-1, j, x, y, a, n, m, vis, dp);
        int right = dfs(i, j+1, x, y, a, n, m, vis, dp);
        int down  = dfs(i+1, j, x, y, a, n, m, vis, dp);
        int left  = dfs(i, j-1, x, y, a, n, m, vis, dp);
        vis[i][j] = 0;
        ans = 1 + min(min(up, right), min(down, left));
        return ans;
        
    }
    
    int shortestDistance(int n, int m, vector<vector<int>> A, int x, int y) {
        // code here
        int curx = 0, cury = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // dp(N, vector<int>(M, -1));
        // int ans = dfs(curx, cury, X, Y, A, N, M, vis, dp);
        if(A[0][0]==0) return -1;
        queue<pair<int,int>> q;
        q.push({0, 0});
        int d = 0;
        while(!q.empty())
        {
            int k = q.size();
            for(int l=0; l<k; l++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i==x && j==y && A[i][j]==1) return d;
                if(i<0 || j<0 || i>=n || j>=m || A[i][j]==0 || vis[i][j]==1) continue;
                vis[i][j] = 1;
                q.push({i-1, j});
                q.push({i, j+1});
                q.push({i+1, j});
                q.push({i, j-1});
            }
            d++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends