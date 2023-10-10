class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<int> s;
        int start = 0;
        int ans = nums.size();
        // for(int i=0; i<nums.size(); i++) cout<<nums[i]<<" ";
        for(int i=0; i<nums.size(); i++) {
            while(i<nums.size() && nums[i]<nums[start]+nums.size()) {
                s.insert(nums[i]); 
                i++;
            }
            // cout<<'\n'<<nums[start]<<" "<<nums.size()-s.size()<<" ";
            // for(auto it:s) cout<<it<<" ";
            ans = min(ans, int(nums.size()-s.size()));
            s.erase(nums[start]);
            start++;
            i--;
        }
        return ans;
    }
};