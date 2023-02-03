class Solution {
public:
    string convert(string s, int num) {
        if(s.size() <= 2 || num <= 1) return s;
        int n = s.size();
        vector<string> v(num, "");
        int r = 0;
        int forward = 1;
        for(int i=0; i<n; i++)
        {
            v[r] += s[i];
            // cout<<r<<" "<<v[r]<<'\n';
            if(forward) 
            {
                r++;
                if(r == num)
                {
                    forward = 0;
                    r = num-2;
                    continue;
                }
            }
            else 
            {
                r--;
                if(r == -1)
                {
                    forward = 1;
                    r = 1;
                    continue;
                }
            }
        }
        string ans = "";
        for(int i=0; i<num; i++) ans += v[i];
        return ans;
    }
};