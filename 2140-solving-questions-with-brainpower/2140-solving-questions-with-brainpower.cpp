class Solution {
public:
    long long int dp[100007] = {-1};
    long long solve(vector<vector<int>>& questions, int ind)
    {
        if(ind >= questions.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        long long int take = questions[ind][0] + solve(questions, ind+questions[ind][1]+1);
        long long int nottake  = solve(questions, ind+1);
        return dp[ind] = max(take, nottake);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        long long int ans = 0;
        memset(dp, -1, sizeof(dp));
        ans = solve(questions, 0);
        return ans;
    }
};