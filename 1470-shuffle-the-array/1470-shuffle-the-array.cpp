class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int s1 = 0;
        int s2 = n;
        for(int i=0; i<n; i++)
        {
            ans.push_back(nums[s1]);
            ans.push_back(nums[s2]);
            s1++;
            s2++;
        }
        return ans;
    }
};