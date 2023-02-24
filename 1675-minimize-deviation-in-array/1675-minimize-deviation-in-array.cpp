class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        long long int n = nums.size();
        priority_queue<int> pq;
        int mn = INT_MAX;
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(nums[i]%2 == 1) nums[i]*=2;
            pq.push(nums[i]);
            mn = min(mn, nums[i]);
        }
        while(pq.top()%2 == 0)
        {
            int x = pq.top();
            pq.pop();
            x /= 2;
            pq.push(x);
            mn = min(mn, x);
            ans = min(ans, pq.top()-mn);
        }
        ans = min(ans, pq.top()-mn);
        return ans;
    }
};