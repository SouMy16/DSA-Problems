class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1) q.push({{i,j},0});
            }
        }
        if(q.empty() || q.size() == n*n) return -1;
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            ans = max(ans, dist);
            q.pop();
            if(x-1 >= 0 && grid[x-1][y] == 0)
            {
                grid[x-1][y] = 1;
                q.push({{x-1, y}, dist+1});
            }
            if(x+1 < n && grid[x+1][y] == 0)
            {
                grid[x+1][y] = 1;
                q.push({{x+1, y}, dist+1});
            }
            if(y-1 >= 0 && grid[x][y-1] == 0)
            {
                grid[x][y-1] = 1;
                q.push({{x, y-1}, dist+1});
            }
            if(y+1 < n && grid[x][y+1] == 0)
            {
                grid[x][y+1] = 1;
                q.push({{x, y+1}, dist+1});
            }
        }
        return ans;
    }
};