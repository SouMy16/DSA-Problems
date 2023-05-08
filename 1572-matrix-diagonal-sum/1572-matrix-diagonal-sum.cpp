class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        for(int i=0; i<n; i++) ans+=(mat[i][i]+mat[i][n-1-i]);
        if(n%2) ans -= mat[n/2][n/2];
        return ans;
    }
};