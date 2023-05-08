class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
            {
                if(i==j) ans += mat[i][j];
                else if(i+j==n-1) ans+=mat[i][j];
            }
        }
        return ans;
    }
};