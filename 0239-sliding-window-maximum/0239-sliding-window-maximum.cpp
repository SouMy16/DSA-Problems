class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> m;
        priority_queue<int> pq;
        for(int i=0; i<k; i++) {
            pq.push(nums[i]);
            m[nums[i]]++;
        }
        ans.push_back(pq.top());
        for(int i=k; i<nums.size(); i++) {
            m[nums[i-k]]--;
            while(!pq.empty() && m[pq.top()] == 0) pq.pop();
            pq.push(nums[i]);
            m[nums[i]]++;
            ans.push_back(pq.top());
        }
        return ans;
    }
};