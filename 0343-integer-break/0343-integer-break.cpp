class Solution {
public:
    int integerBreak(int n) {
        int mx = 0;
        for(int i=2; i<=n; i++) {
            vector<int> values(i, n/i);
            for(int j=0; j<n%i; j++) values[j]++;
            int prod = 1;
            for(int j=0; j<i; j++) prod *= values[j];
            if(prod<mx) break;
            mx = max(mx, prod);
        }
        return mx;
    }
};