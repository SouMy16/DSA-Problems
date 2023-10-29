class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size();
        for(int i=0; i<k; i++) {
            while(k>0 && nums[k-1]==val) {
                k--;
                if(k == 0 || k<=i) return k;
            }
            if(nums[i] == val) {
                swap(nums[i], nums[k-1]);
            }
        }
        return k;
    }
};