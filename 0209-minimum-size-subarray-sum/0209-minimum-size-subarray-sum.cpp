class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int start = 0;
        int n = nums.size();
        int ans = n+3;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            while(sum-nums[start] >= target) sum-=nums[start++];
            if(sum >= target) ans = min(ans, i-start+1);
        }
        if(ans > n) return 0;
        return ans;
    }
};