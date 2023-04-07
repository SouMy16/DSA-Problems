class Solution {
public:
    void dfs(vector<vector<int>> &grid, int x, int y)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(x<0 || y<0 || x>=n || y>=m) return;
        if(grid[x][y] == 0) return;
        grid[x][y]=0;
        int ax[]={1, 0, -1, 0};
        int ay[]={0, 1, 0, -1};
        for(int i=0; i<4; i++)
        {
            int xx = x+ax[i];
            int yy = y+ay[i];
            if(xx<0 || yy<0 || xx>=n || yy>=m) continue;
            if(grid[xx][yy]==1) dfs(grid, xx, yy);
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++)
        {
            dfs(grid, i, 0);
            dfs(grid, i, m-1);
        }
        for(int i=0; i<m; i++)
        {
            dfs(grid, 0, i);
            dfs(grid, n-1, i);
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans += grid[i][j];
            }
        }
        return ans;
    }
};