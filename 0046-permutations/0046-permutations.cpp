class Solution {
public:
    
    void solve(vector<int> &nums, vector<int> &cur, vector<vector<int>> &ans, unordered_map<int,int> &m)
    {
        if(cur.size() == nums.size())
        {
            ans.push_back(cur);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(m[nums[i]] == 0) 
            {
                m[nums[i]] = 1;
                cur.push_back(nums[i]);
                solve(nums, cur, ans, m);
                cur.pop_back();
                m[nums[i]] = 0;
            }
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> cur;
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++) m[nums[i]] = 0;
        solve(nums, cur, ans, m);
        return ans;
    }
};