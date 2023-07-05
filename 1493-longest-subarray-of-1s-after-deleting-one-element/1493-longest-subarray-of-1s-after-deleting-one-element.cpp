class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> a;
        int cur = 0;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                if(cur != 0) a.push_back(cur);
                a.push_back(0);
                cur = 0;
            }
            else cur++;
        }
        int ans = 0;
        if(cur) a.push_back(cur);
        for(int i=0; i<a.size(); i++)
        {
            ans = max(ans, a[i]);
            if(i>0 && a[i] == 0 && i<a.size()-1) ans = max(ans, a[i-1]+a[i+1]);
        }
        if(a.size() == 1 && a[0] != 0) ans = a[0]-1;
        return ans;
    }
};