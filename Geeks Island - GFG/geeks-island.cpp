//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    void DFS(vector<vector<int>> &v, int i, int j, vector<vector<int>> &mat)
    {
        if(i<0 || i>=mat.size()) return;
        if(j<0 || j>=mat[0].size()) return;
        if(v[i][j] == 1) return;
        v[i][j] = 1;
        if(i>0 && v[i-1][j] == 0 && mat[i-1][j] >= mat[i][j]) DFS(v, i-1, j, mat);
        if(i<mat.size()-1 && v[i+1][j] == 0 && mat[i+1][j] >= mat[i][j]) DFS(v, i+1, j, mat);
        if(j>0 && v[i][j-1] == 0 && mat[i][j-1] >= mat[i][j]) DFS(v, i, j-1, mat);
        if(j<mat[0].size()-1 && v[i][j+1] == 0 && mat[i][j+1] >= mat[i][j]) DFS(v, i, j+1, mat);
        return;
    }


    int water_flow(vector<vector<int>> &mat,int n,int m){
    // Write your code here.
        int ans = 0;
        vector<vector<int>> io(n, vector<int> (m, 0));
        for(int i=0; i<n; i++) 
        {
            DFS(io, i, 0, mat);
            io[i][0] = 1;
        }
        for(int j=0; j<m; j++) 
        {
            DFS(io, 0, j, mat);
            io[0][j] = 1;
        }
        
        vector<vector<int>> as(n, vector<int> (m, 0));
        for(int i=0; i<n; i++)
        {
            DFS(as, i, m-1, mat);
            as[i][m-1] = 1;
        }
        for(int j=0; j<m; j++)
        {
            DFS(as, n-1, j, mat);
            as[n-1][j] = 1;
        }
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(io[i][j] + as[i][j] == 2) 
                {
                    ans++;
                    // cout<<i<<" "<<j<<'\n';
                }
            }
                
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends