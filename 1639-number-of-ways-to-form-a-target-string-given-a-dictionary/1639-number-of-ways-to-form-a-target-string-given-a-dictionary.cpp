class Solution {
public:
    int mod = 1e9+7;
    int dp[1001][1001];
    int solve(vector<string> &words, int i, int j, string &target, vector<vector<int>> &freq)
    {
        if(dp[i][j] != -1) return dp[i][j];
        if(j == target.size()) return dp[i][j] = 1;
        if(i == words[0].size()) return dp[i][j] = 0;
        int nottake = solve(words, i+1, j, target, freq);
        int take = 0;
        int c = 0;
        // for(int k=0; k<words.size(); k++)
        // {
        //     if(words[k][i] == target[j])
        //     {
        //         c++;
        //     }
        // }
        c = freq[target[j]-'a'][i];
        take = (1LL * (c%mod) * (solve(words, i+1, j+1, target, freq)%mod))%mod;
        return dp[i][j] = (nottake+take)%mod;
    }
    int numWays(vector<string>& words, string target) {
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> frequency(26, vector<int>(words[0].size(), 0));
        for(int i=0; i<words.size(); i++)
        {
            for(int j=0; j<words[i].size(); j++)
            {
                frequency[words[i][j]-'a'][j]++;
            }
        }
        return solve(words, 0, 0, target, frequency);
    }
};