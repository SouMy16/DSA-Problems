class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0) return 0;
            if(nums[i]<0) ans++;
        }
        if(ans%2) ans=-1;
        else ans=1;
        return ans;
    }
};