//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void DFS(int i, int j, vector<vector<char>> &mat) {
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()) return;
        if(mat[i][j] == 'X' || mat[i][j] == '#') return;
        mat[i][j] = '#';
        DFS(i-1, j, mat);
        DFS(i, j-1, mat);
        DFS(i+1, j, mat);
        DFS(i, j+1, mat);
        return;
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 || j==0 || i==n-1 || j==m-1) {
                    if(mat[i][j] == 'O') {
                        DFS(i, j, mat);
                    }
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 'O') mat[i][j] = 'X';
                if(mat[i][j] == '#') mat[i][j] = 'O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends