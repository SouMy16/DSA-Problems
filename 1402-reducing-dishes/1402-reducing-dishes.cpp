class Solution {
public:
    int maxCoeff(vector<int>& satisfaction, int ind, int prev, vector<vector<int>>& dp)
    {
        if(ind == satisfaction.size()) return 0;
        if(dp[prev][ind]!=-1) return dp[prev][ind];
        int op1 = ((prev+1) * satisfaction[ind]) + maxCoeff(satisfaction, ind+1, prev+1, dp);
        int op2 = maxCoeff(satisfaction, ind+1, prev, dp);
        return dp[prev][ind] = max(op1, op2);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(satisfaction.size()+1, vector<int>(satisfaction.size()+1, -1));
        return maxCoeff(satisfaction, 0, 0, dp);
    }
};