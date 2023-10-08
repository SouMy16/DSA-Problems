class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &nums1, int i, vector<int> &nums2, int j) {
        if(i==nums1.size() || j==nums2.size()) return INT_MIN;
        if(dp[i][j] != INT_MIN) return dp[i][j];
        int take = nums1[i]*nums2[j]+max(0, solve(nums1, i+1, nums2, j+1));
        int nottake = max(solve(nums1, i+1, nums2, j+1), max(solve(nums1, i+1, nums2, j), solve(nums1, i, nums2, j+1)));
        return dp[i][j] = max(take, nottake);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp = vector<vector<int>> (501, vector<int>(501, INT_MIN));
        return solve(nums1, 0, nums2, 0);
    }
};