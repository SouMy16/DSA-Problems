class Solution {
public:
    int dp[501][501];
    int LCS(vector<int> &a, vector<int> &b, int i, int j)
    {
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) return dp[i][j] = 1+LCS(a, b, i-1, j-1);
        return dp[i][j] = max(LCS(a, b, i-1, j), LCS(a, b, i, j-1));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        memset(dp, -1, sizeof(dp));
        int ans = LCS(nums1, nums2, n1-1, n2-1);
        return ans;
    }
};