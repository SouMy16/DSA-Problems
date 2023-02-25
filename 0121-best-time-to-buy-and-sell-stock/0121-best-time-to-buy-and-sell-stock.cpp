class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mincost = prices[0];
        for(int i=1; i<prices.size(); i++)
        {
            mincost = min(mincost, prices[i]);
            ans = max(ans, prices[i]-mincost);
        }
        return ans;
    }
};