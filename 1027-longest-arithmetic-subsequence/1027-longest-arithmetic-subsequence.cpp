class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(1001, -1));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                int d = nums[j]-nums[i];
                dp[i][500+d] = max(1+dp[j][500+d], dp[i][500+d]);
                ans = max(ans, dp[i][500+d]);
            }
        }
        return ans+2;
    }
};