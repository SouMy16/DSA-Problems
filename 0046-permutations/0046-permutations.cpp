class Solution {
public:
    
    void solve(vector<int> nums, int n, vector<int> cur, vector<vector<int>> &ans)
    {
        if(n==0)
        {
            cur.push_back(nums[n]);
            ans.push_back(cur);
            return;
        }
        for(int i=0;i<=n;i++)
        {
            vector<int> temp = nums;
            cur.push_back(nums[i]);
            temp.erase(temp.begin()+i);
            solve(temp,n-1,cur,ans);
            cur.pop_back();
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int> cur;
        solve(nums,n-1,cur,ans);
        return ans;
    }
};