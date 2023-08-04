class Solution {
public:
    map<string, int> m;
    map<pair<string, int>, bool> dp;
    bool isBreak(string &s, string x, int ind)
    {
        if(ind == s.size())
        {
            if(s != x && m[x] == 1) {
                cout<<x<<' ';
                return true;
            }
            return false; 
        }
        if(dp.find({x, ind}) != dp.end()) return dp[{x, ind}];
        bool ans = false;
        x.push_back(s[ind]);
        if(m[x] == 1)
        {
            string emp = "";
            ans |= isBreak(s, emp, ind+1);
        }
        ans |= isBreak(s, x, ind+1);
        return dp[{x, ind}] = ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        for(int i=0; i<n; i++)
        {
            m[wordDict[i]] = 1;
        }
        string cur = "";
        m[""] = 1;
        return isBreak(s, cur, 0);
    }
};