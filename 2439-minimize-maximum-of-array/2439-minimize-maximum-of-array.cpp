class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int ans = 0;
        long long int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            int x = (sum+i) / (i+1); 
            ans = max(ans, x);
        }
        return ans;
    }
};