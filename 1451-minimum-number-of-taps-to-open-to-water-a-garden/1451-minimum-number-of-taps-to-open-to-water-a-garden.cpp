class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int ans = 0;
        vector<vector<int>> v;
        for(int i=0; i<=n; i++) {
            if(ranges[i]!=0) v.push_back(vector<int>{max(0, i-ranges[i]), min(n, i+ranges[i])});
        }
        if(v.size() == 0) return -1;
        sort(v.begin(), v.end());
        int start = 0;
        for(int i=0; i<v.size(); i++) {
            int mx = -1;
            while(i<v.size() && v[i][0]<=start) {
                mx = max(mx, v[i][1]);
                i++;
            }
            i--;
            if(mx == -1) return mx;
            start = mx;
            ans++;
            if(start == n) return ans;
        }
        if(start != n) return -1;
        return ans;
    }
};