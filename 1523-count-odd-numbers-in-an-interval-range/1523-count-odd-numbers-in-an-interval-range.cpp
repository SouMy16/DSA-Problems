class Solution {
public:
    int countOdds(int low, int high) {
        // long long int ans = 0;
        int ans = high-low;
        ans /= 2;
        if(high%2 == 1 || low%2 == 1) ans++;
        return ans;
    }
};