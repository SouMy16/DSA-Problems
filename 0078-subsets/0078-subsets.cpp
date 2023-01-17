class Solution {
public:
    void solve(vector<int> &nums, int i, vector<vector<int>> &ans, vector<int> cur, map<vector<int>, int> &m)
    {
        if(i==nums.size()) 
        {
            if(m[cur] != 1)
            {
                ans.push_back(cur);
                m[cur] = 1;
            }
            return;
        }
        solve(nums, i+1, ans, cur, m);
        cur.push_back(nums[i]);
        solve(nums, i+1, ans, cur, m);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        map<vector<int>, int> m;
        vector<int> cur;
        solve(nums, 0, ans, cur, m);
        return ans;
    }
};