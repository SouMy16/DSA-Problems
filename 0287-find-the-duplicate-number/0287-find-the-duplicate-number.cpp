class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        if(nums.size()<3) return nums[0];
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(fast!=slow);
        slow = 0;
        while(fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
    
};