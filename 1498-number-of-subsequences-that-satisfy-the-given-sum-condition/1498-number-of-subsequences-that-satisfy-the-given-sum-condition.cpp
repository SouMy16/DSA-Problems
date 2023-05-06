class Solution {
public:
    long long mod = 1e9+7;
    long long binpow(long long a, long long b) {
        if (b == 0)
            return 1;
        long long res = binpow(a, b / 2);
        if (b % 2)
            return (res * res * a)%mod;
        else
            return (res * res)%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int j = n-1;
        int ans = 0;
        // int mod = 1e9+7;
        for(int i=0; i<n; i++)
        {
            if(nums[i]+nums[i] > target) break;
            while(nums[i]+nums[j] > target && j>i)
            {
                j--;
            }
            if(j<i) break;
            int l = j-i;
            long long int p = binpow(1LL*2, 1LL*l);
            p%=mod;
            ans += p%mod;
            ans %= mod;
            // ans = (ans%mod + pow(2,j-i)%mod)mod;
        }
        return ans;
    }
};