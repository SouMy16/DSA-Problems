class Solution {
public:
    double average(vector<int>& salary) {
        double ans = 0;
        int n = salary.size();
        int mn = salary[0];
        int mx = mn;
        for(int i=0; i<n; i++)
        {
            ans += salary[i];
            mn = min(mn, salary[i]);
            mx = max(mx, salary[i]);
        }
        // ans -= (mn+mx);
        // ans -= mx;
        n -= 2;
        // ans /= n;
        ans = (ans-mn-mx)/n;
        return ans;
    }
};