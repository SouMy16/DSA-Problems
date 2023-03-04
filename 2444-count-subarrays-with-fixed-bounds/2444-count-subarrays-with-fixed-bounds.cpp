class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int x = 0;
        int n = nums.size();
        vector<int> mxa, mna;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == minK) mna.push_back(i);
            if(nums[i] == maxK) mxa.push_back(i);
        }
        // for(int i=0; i<mna.size(); i++) cout<<mna[i]<<" "; cout<<'\n';
        // for(int i=0; i<mxa.size(); i++) cout<<mxa[i]<<" "; cout<<'\n';
        for(int i=0; i<n; i++)
        {
            if(nums[i] < minK || nums[i] > maxK) continue;
            int start = i-1;
            while(i<nums.size() && nums[i]<=maxK && nums[i]>=minK) i++;
            int last = i;
            for(int j=start+1; j<last; j++)
            {
                if(nums[j] == minK)
                {
                    int x = lower_bound(mxa.begin(), mxa.end(), j)-mxa.begin();
                    if(x == mxa.size()) continue;
                    int c1 = j-start;
                    int c2 = last-mxa[x];
                    if(c2<0) continue;
                    ans += c1*c2;
                    start = j;
                    continue;
                    // cout<<"Added "<<c1*c2<<" at index "<<j<<" with c1: "<<c1<<", c2: "<<c2<<", x:"<<x<<'\n';
                }
                if(nums[j] == maxK)
                {
                    int x = lower_bound(mna.begin(), mna.end(), j)-mna.begin();
                    if(x == mna.size()) continue;
                    int c1 = j-start;
                    int c2 = last-mna[x];
                    if(c2<0) continue;
                    ans += c1*c2;
                    start = j;
                    continue;
                    // cout<<"Added "<<c1*c2<<" at index "<<j<<" with c1: "<<c1<<", c2: "<<c2<<'\n';
                }
                // if(nums[j] == minK || nums[j] == maxK) start = j;
            }
        }
        return ans;
    }
};