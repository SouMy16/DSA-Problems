class Solution {
public:
    int search(vector<int>& nums, int target) {
        int h=nums.size()-1,l=0;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target && nums[mid]>=nums[0])
            {
                // l=mid+1;
                if(target>=nums[0]) h=mid-1;
                else l=mid+1;
            }
            else if(nums[mid]<target && nums[mid]<nums[0])
            {
                if(target<nums[0]) l=mid+1;
                else h=mid-1;
            }
            else if(nums[mid]>target && nums[mid]<nums[0])
            {
                h=mid-1;
            }
            else if(nums[mid]<target && nums[mid]>=nums[0])
            {
                l=mid+1;
            }
        }
        return -1;
    }
};