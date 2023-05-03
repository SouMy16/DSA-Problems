class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i=0; i<n1; i++)
        {
            m[nums1[i]] = 1;
        }
        for(int i=0; i<n2; i++)
        {
            if(m[nums2[i]] == 0) m[nums2[i]] = 2;
            else if(m[nums2[i]] != 2) m[nums2[i]] = 3;
        }
        vector<vector<int>> ans(2);
        for(auto it: m)
        {
            if(it.second==1) ans[0].push_back(it.first);
            if(it.second==2) ans[1].push_back(it.first);
        }
        return ans;
    }
};