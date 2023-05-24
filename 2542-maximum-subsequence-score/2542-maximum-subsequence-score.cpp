class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        vector<pair<long long, long long>> v;
        int n = nums1.size();
        for(int i=0; i<n; i++) v.push_back({nums2[i], nums1[i]});
        sort(v.begin(), v.end());
        vector<long long> sum(n, 0);
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int i=n-k; i<n; i++) 
        {
            pq.push(v[i].second);
            sum[n-k] += v[i].second;
        } 
        long long cur = sum[n-k];
        cur -= pq.top();
        pq.pop();
        for(int i=n-k-1; i>=0; i--)
        {
            // cur -= pq.top();
            cur += v[i].second;
            sum[i] = cur;
            cur -= v[i].second;
            if(!pq.empty() && pq.top()<v[i].second)
            {
                cur -= pq.top();
                pq.pop();
                pq.push(v[i].second);
                cur += v[i].second;
            }
        }
        for(int i=0; i<n; i++)
        {
            long long cur = 0;
            long long mn = v[i].first;
            cur = mn;
            cur *= sum[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};