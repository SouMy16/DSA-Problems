class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int j = k;
        long long int cur = 0;
        if(2*k >= n) return ans;
        for(int i=0; i<=2*k; i++)
        {
            cur += nums[i];
        }
        ans[k] = cur/(2*k+1);
        for(int j=k+1; j<n-k; j++)
        {
            cur -= nums[j-1-k];
            cur += nums[j+k];
            ans[j] = cur/(2*k+1);
        }
        return ans;
    }
};