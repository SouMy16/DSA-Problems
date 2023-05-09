class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = nums[0];
        int n = nums.size();
        for(int i=0; i<=mx && i<n; i++)
        {
            mx = max(mx, i+nums[i]);
            if(mx>=n-1) return true;
        }
        return false;
    }
};