class Solution {
public:
    unordered_map<int, unordered_map<int,int>> dp;
    bool solve(vector<int> &nums, int st, int ind) {
        if(st==ind && ind>=nums.size()) return true;
        if(ind>=nums.size()) return false;
        bool ans = false;
        if(dp[ind].find(st) != dp[ind].end()) return dp[ind][st];
        if(ind == st) {
            ans |= solve(nums, st, ind+1);
        }
        if(ind == st+1){
            if(nums[st] == nums[ind]){
                // 2 equal h to lelo
                ans |= solve(nums, ind+1, ind+1);
                // 2 equal h to 3rd check kro
                ans |= solve(nums, st, ind+1);
            }
            else if(nums[ind] == 1+nums[st]){
                // 2 consecutive increasing to 3rd k liye check kro 
                ans |= solve(nums, st, ind+1);
            }
            else{
                // wrna to false hi h
                return dp[ind][st] = false;
            }
        }
        if(ind == st+2){
            if(nums[st] == nums[st+1] && nums[st+1] == nums[ind]){
                // 3 consecutive h to lelo bs
                ans |= solve(nums, ind+1, ind+1);
            }
            else if(1+nums[st] == nums[st+1] && 1+nums[st+1] == nums[ind]){
                // 3 consecutive increasing h to lelo bs
                ans |= solve(nums, ind+1, ind+1);
            }
            else /*wrna false*/ return dp[ind][st] = false;
        }
        return dp[ind][st] = ans;
    }

    bool validPartition(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};