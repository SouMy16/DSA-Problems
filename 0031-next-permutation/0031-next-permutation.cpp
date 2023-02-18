class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ch = -1;
        for(int i = nums.size()-1; i>0; i--)
        {
            if(nums[i] > nums[i-1])
            {
                ch = i-1;
                break;
            }
        }
        if(ch != -1)
        {
            for(int i=nums.size()-1; i>0; i--)
            {
                if(nums[i] > nums[ch])
                {
                    swap(nums[ch], nums[i]);
                    sort(nums.begin()+ch+1, nums.end());
                    break;
                }
            }
        }
        else sort(nums.begin(), nums.end());
        return;
    }
};