static bool mycomp(pair<int,int> &a, pair<int,int> &b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        int mx = 0;
        for(int i=0; i<ages.size(); i++)
        {
            v.push_back({ages[i], scores[i]});
            mx = max(mx, scores[i]);
            // m[scores[i]] = max(m[scores[i]], ages[i]);
        }
        sort(v.begin(), v.end(), mycomp);
        // vector<int> s;
        // int mx = 0;
        // for(int i=0; i<ages.size(); i++) 
        // {
        //     s.push_back(v[i].second);
        //     mx = max(mx, v[i].second);
        // }
        vector<int> dp(ages.size()+2, 0);
        int ans = mx;
        dp[0] = v[0].second;
        for(int i=0; i<ages.size(); i++)
        {
            dp[i] = v[i].second;
            for(int j=0; j<i; j++)
            {
                if(v[j].second <= v[i].second) dp[i] = max(dp[i], dp[j] + v[i].second);
            }
            ans = max(ans, dp[i]);
        }
        // vector<vector<int>> dp(ages.size()+1, vector<int> (1003, -1));
        // ans = maxScore(s, 0, mx);
        return ans;
    }
};