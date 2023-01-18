class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ksum = nums[0];
        int sum = 0;
        int minsum = nums[0];
        int n = nums.size();
        int cur = 0;
        for(int i=0; i<n; i++)
        {
            
            ksum = max(ksum, nums[i]);
            cur += nums[i];
            if(cur < 0)
            {
                ksum = max(ksum, cur);
                cur = 0;
                continue;
            }
            ksum = max(ksum, cur);
        }
        cur = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            if(cur + nums[i] > 0)
            {
                minsum = min(cur, minsum);
                cur = 0;
                continue;
            }
            cur += nums[i];
            minsum = min(minsum, cur);
            minsum = min(minsum, nums[i]);
        }
        // cout<<sum<<" "<<minsum<<" "<<ksum<<'\n';
        if(minsum >= sum) return ksum;
        int ans = 0;
        ans = max(ksum, sum-minsum);
        // if(minsum == sum) return ksum;
        return ans;
    }
};