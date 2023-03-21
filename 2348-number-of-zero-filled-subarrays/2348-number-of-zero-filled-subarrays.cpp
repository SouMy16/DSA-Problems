class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long zero=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0) zero=0;
            if(zero==0 && nums[i]==0) ans++,zero=1;
            else if(zero!=0 && nums[i]==0)
            {
                zero++;
                ans+=(zero);
            }
        }
        return ans;
    }
};