class Solution {
public:
    // int findPath(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& vis)
    // {
    //     if(x>=grid.size() || y>=grid.size() || x<0 || y<0) return 1e7;
    //     if(grid[x][y] == 1) return 1e7;
    //     if(x == grid.size()-1 && y == grid.size()-1) return 1;
    //     int ans = INT_MAX;
    //     int arr[] = {0, -1, 1};
    //     for(int i=0; i<3; i++)
    //     {
    //         for(int j=0; j<3; j++)
    //         {
    //             if(i==0 && j==0) continue;
    //             x += arr[i];
    //             y += arr[j];
    //             if(x>=grid.size() || y>=grid.size() || x<0 || y<0) 
    //             {
    //                 x -= arr[i];
    //                 y -= arr[j];
    //                 continue;
    //             }
    //             else{
    //                 if(grid[x][y] == 0 && vis[x][y] == 0) ans = min(ans, findPath(grid, x, y));
    //                 x -= arr[i];
    //                 y -= arr[j];
    //             }
    //         }
    //     }
    //     return 1+ans;
    // }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[n-1][n-1] == 1 || grid[0][0] == 1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int ans = 0;
        vis[0][0] = 1;
        while(!q.empty())
        {
            ans++;
            int m = q.size();
            for(int k=0; k<m; k++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                vis[x][y] = 1;
                if(x == n-1 && y == n-1) return ans;
                int arr[] = {0, -1, 1};
                for(int i=0; i<3; i++)
                {
                    for(int j=0; j<3; j++)
                    {
                        if(i==0 && j==0) continue;
                        x += arr[i];
                        y += arr[j];
                        if(x>=grid.size() || y>=grid.size() || x<0 || y<0) 
                        {
                            x -= arr[i];
                            y -= arr[j];
                            continue;
                        }
                        else{
                            if(grid[x][y] == 0 && vis[x][y] == 0) 
                            {
                                vis[x][y] = 1;
                                q.push({x,y});
                            }
                            x -= arr[i];
                            y -= arr[j];
                        }
                    }
                }
            }
        }
        return -1;
    }
};