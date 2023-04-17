class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(), false);
        int mx = 0;
        for(int i=0; i<candies.size(); i++) mx = max(mx, candies[i]);
        for(int i=0; i<candies.size(); i++)
        {
            if(extraCandies+candies[i] >= mx) ans[i] = true;
            else ans[i] = false;
        }
        return ans;
    }
};