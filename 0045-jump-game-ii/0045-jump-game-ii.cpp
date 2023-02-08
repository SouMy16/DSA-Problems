class Solution {
public:
    int jump(vector<int>& nums) {
        int pos=0,n=nums.size();
        int jumps=0,maxii=0;
        for(int i=0;i<n;i++)
        {
            if(pos==i) continue;
            if(nums[i]+i>nums[maxii]+maxii) maxii=i;
            if(nums[pos]+pos==i || i==n-1)
            {
                pos=maxii;
                // i=maxii-1;
                jumps++;
                if(pos==n-1) return jumps;
                // if(pos+nums[pos]>=n-1) return jumps+1;
            }
        }
        return jumps;
    }
};