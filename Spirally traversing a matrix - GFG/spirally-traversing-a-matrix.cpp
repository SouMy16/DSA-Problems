//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int rs = 0, re = r;
        int cs = 0, ce = c;
        while(rs<re || cs<ce)
        {
            for(int i=cs; i<ce; i++) ans.push_back(matrix[rs][i]);
            rs++;
            if(rs == re || ce == cs) break;
            for(int i=rs; i<re; i++) ans.push_back(matrix[i][ce-1]);
            ce--;
            if(rs == re || ce == cs) break;
            for(int i=ce-1; i>=cs; i--) ans.push_back(matrix[re-1][i]);
            re--;
            if(rs == re || ce == cs) break;
            for(int i=re-1; i>=rs; i--) ans.push_back(matrix[i][cs]);
            cs++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends