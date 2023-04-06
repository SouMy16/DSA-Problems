class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        // if(grid[x][y]==0 && (x==0 || y==0 || x==grid.size()-1 || y==grid[0].size())) return 0;
        grid[x][y] = 1;
        int ax[] = {-1, 0, 1, 0};
        int ay[] = {0, 1, 0, -1};
        // int ans = 1;
        for(int i=0; i<4; i++)
        {
            int xx = x+ax[i];
            int yy = y+ay[i];
            if(xx<0 || xx>=grid.size() || yy<0 || yy>=grid[0].size()) continue;
            if(grid[xx][yy] == 0)
            {
                dfs(grid, xx, yy);
            }
        }
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(grid[i][0]==0) dfs(grid, i, 0);
            if(grid[i][m-1]==0) dfs(grid, i, m-1);
        }
        for(int i=0; i<m; i++)
        {
            if(grid[0][i]==0) dfs(grid, 0, i);
            if(grid[n-1][i]==0) dfs(grid, n-1, i);
        }
        for(int i=1; i<n-1; i++)
        {
            for(int j=1; j<m-1; j++)
            {
                if(grid[i][j]==0)
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};