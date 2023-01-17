class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        // sort(nums.begin(),nums.end());
        vector<pair<int,int> > x;
        for(int i=0;i<nums.size();i++) x.push_back({nums[i],i});
        sort(x.begin(),x.end());
        for(int i=0,j=nums.size()-1;i<j;)
        {
            if(x[i].first+x[j].first<target) i++;
            else if(x[i].first+x[j].first>target) j--;
            else {
                ans.push_back(x[i].second);
                ans.push_back(x[j].second);
                break;
            }
        }
        return ans;
    }
};