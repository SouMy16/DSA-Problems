class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        int ans = -1;
        while(!q.empty()){
            ans++;
            int x = q.size();
            for(int k=0; k<x; k++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                grid[i][j] = 2;
                if(i>0 && grid[i-1][j] == 1) 
                {
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                }
                if(j>0 && grid[i][j-1] == 1) 
                {
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                }
                if(i+1<n && grid[i+1][j] == 1) 
                {
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                }
                if(j+1<m && grid[i][j+1] == 1) 
                {
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                }
            }
        }
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(grid[i][j] == 1) return -1;
        return max(0, ans);
    }
};