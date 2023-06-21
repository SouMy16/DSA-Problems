class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        long long int ans;
        long long int prev = 0;
        long long int suc = 0;
        long long int afct = 0;
        long long int bfct = 0;
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) v.push_back({nums[i], cost[i]});
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++) nums[i] = v[i].first, cost[i] = v[i].second;
        for(int i=1; i<n; i++) afct += cost[i], suc += 1LL*(nums[i]-nums[0])*cost[i];
        ans = suc;
        // cout<<ans<<'\n';
        for(int i=1; i<n; i++)
        {
            suc = suc - 1LL*(nums[i]-nums[i-1])*afct;
            afct -= cost[i];
            bfct += cost[i-1];
            prev = prev + 1LL*bfct*(nums[i]-nums[i-1]);
            // cout<<nums[i]<<" "<<prev<<" + "<<suc<<" = "<<prev+suc<<'\n';
            ans = min(ans, suc+prev);
        }
        return ans;
    }
};