class Solution {
public:
    int convert(int a, vector<int> &mapping) {
        int p = 0, f = 0;
            int x = 0;
            // cout<<a<<" ";
            if(a == 0) x = mapping[0];
            while(a) {
                int r = a%10;
                a /= 10;
                r = mapping[r];
                x *= 10;
                x += r;
                if(r == 0 && f == 0) p++;
                else f = 1;
            }
            while(x) {
                int r = x%10;
                x /= 10;
                a *= 10;
                a += r;
            }
            if(p != 0) a *= pow(10, p);
            return a;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // mp = mapping;
        // auto myComp = [&mapping] (int a, int b) {
        //     int p = 0, f = 0;
        //     int x = 0;
        //     // cout<<a<<" ";
        //     if(a == 0) x = mapping[0];
        //     while(a) {
        //         int r = a%10;
        //         a /= 10;
        //         r = mapping[r];
        //         x *= 10;
        //         x += r;
        //         if(r == 0 && f == 0) p++;
        //         else f = 1;
        //     }
        //     while(x) {
        //         int r = x%10;
        //         x /= 10;
        //         a *= 10;
        //         a += r;
        //     }
        //     if(p != 0) a *= pow(10, p);
        //     // cout<<a<<'\n';
        //     p = 0, f = 0;

        //     int y = 0;
        //     // cout<<b<<" ";
        //     if(b == 0) y = mapping[0];
        //     while(b) {
        //         int r = b%10;
        //         b /= 10;
        //         r = mapping[r];
        //         y *= 10;
        //         y += r;
        //         if(r == 0 && f == 0) p++;
        //         else f = 1;
        //     }
        //     while(y) {
        //         int r = y%10;
        //         y /= 10;
        //         b *= 10;
        //         b += r;
        //     }
        //     if(p != 0) b *= pow(10, p);
        //     // cout<<b<<'\n';
        //     p = 0, f = 0;

        //     return a < b;
        // };
        
        vector<pair<int, int>> v;

        for(int i=0; i<nums.size(); i++) {
            v.push_back({convert(nums[i], mapping), i});
        }
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            ans.push_back(nums[v[i].second]);
        }
        return ans;
        // sort(nums.begin(), nums.end(), myComp);
        // return nums;
    }
};