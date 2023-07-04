class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit(32, 0);
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<32; j++)
            {
                bit[j] += abs(nums[i])>>j & 1;
            }
        }
        long long int ans = 0;
        for(int i=0; i<32; i++)
        {
            // cout<<bit[i]<<" ";
            bit[i] %= 3;
            if(bit[i]) ans += pow(2, i);
        }
        int c = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == -ans) c++;
        }
        return c==1?-ans:ans;
    }
};