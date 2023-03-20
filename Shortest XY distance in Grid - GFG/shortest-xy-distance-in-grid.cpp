//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) 
    {
        // code here
        vector<vector<int>> a(n, vector<int>(m, 1000000));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'X'){ 
                    a[i][j] = 0;
                }
            }
        }
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<a[i][j]<<" ";
        //     } 
        //     cout<<'\n';
        // }
        // cout<<'\n';
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 && j==0) continue;
                else if(i==0) a[i][j] = a[i][j-1]+1;
                else if(j==0) a[i][j] = a[i-1][j]+1;
                else a[i][j] = min(a[i][j-1], a[i-1][j])+1;
                if(grid[i][j] == 'X') a[i][j] = 0;
            }
        }
        
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<a[i][j]<<" ";
        //     } 
        //     cout<<'\n';
        // }
        // cout<<'\n';
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(i==n-1 && j==m-1) continue;
                else if(i==n-1) a[i][j] = min(a[i][j], a[i][j+1]+1);
                else if(j==m-1) a[i][j] = min(a[i][j], a[i+1][j]+1);
                else a[i][j] = min(a[i][j], min(a[i+1][j], a[i][j+1])+1);
                if(grid[i][j] == 'X') a[i][j] = 0;
            }
        }
        
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<a[i][j]<<" ";
        //     } 
        //     cout<<'\n';
        // }
        // cout<<'\n';
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         if(i==0 && j==0) continue;
        //         else if(i==0) a[i][j] = min(a[i][j], a[i][j-1]+1);
        //         else if(j==0) a[i][j] = min(a[i][j], a[i-1][j]+1);
        //         else a[i][j] = min(a[i][j], min(a[i][j-1], a[i-1][j])+1);
        //         if(grid[i][j] == 'X') a[i][j] = 0;
        //     }
        // }
        
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){ 
                if(grid[i][j]=='Y'){ 
                    ans = min(ans, a[i][j]);
                }
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends