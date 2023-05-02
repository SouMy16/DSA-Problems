class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0) return 0;
            ans *= nums[i];
            if(ans<0) ans = -1;
            else ans = 1;
        }
        return ans;
    }
};