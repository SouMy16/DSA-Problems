class Solution {
public:
    int jump(vector<int>& nums) {
        queue<pair<int,int>> q;
        q.push({0, 0});
        int n = nums.size();
        vector<int> vis(n+1, -1);
        while(!q.empty())
        {
            int pos = q.front().first;
            int cur = q.front().second;
            q.pop();
            if(pos >= nums.size()-1) return cur;
            for(int i=1; i<=nums[pos]; i++)
            {
                if(pos+i >= nums.size()-1) return cur+1;
                if(vis[pos+i] == -1)
                {
                    vis[pos+i] = 1;
                    q.push({pos+i, cur+1});
                }
            }
        }
        return -1;
    }
};