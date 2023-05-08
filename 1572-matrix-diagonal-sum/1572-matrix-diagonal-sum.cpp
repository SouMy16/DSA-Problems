class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        for(int i=0; i<n; i++) ans+=(mat[i][i]+mat[i][n-1-i]);
        ans = ans - (n%2==1?mat[n/2][n/2]:0);
        return ans;
    }
};