class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 0) continue;
                else ans += 2;
                ans += (grid[i][j]*4);
                if(i > 0) ans -= min(grid[i][j], grid[i-1][j]);
                if(i < n-1) ans -= min(grid[i][j], grid[i+1][j]);
                if(j > 0) ans -= min(grid[i][j], grid[i][j-1]);
                if(j < n-1) ans -= min(grid[i][j], grid[i][j+1]);
            }
        }
        return ans;
    }
};