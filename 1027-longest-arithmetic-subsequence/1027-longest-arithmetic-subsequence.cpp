class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(1001, -1));
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int d = nums[j]-nums[i];
                if(dp[j][500+d] != -1 || dp[i][500+d] != -1) continue;
                int f = nums[j]+d;
                int cur = 2;
                dp[i][500+d]=0;
                dp[j][500+d]=0;
                for(int k=j+1; k<n; k++) if(nums[k] == f) dp[k][500+d]=0, cur++, f+=d;
                if(cur>ans) ans = cur;
                // f=nums[j], cur-=2;
                // for(int k=j+1; k<n; k++) if(nums[k] == f) dp[k][500+d] = cur--, f+=d;
            }
        }
        return ans;
    }
};