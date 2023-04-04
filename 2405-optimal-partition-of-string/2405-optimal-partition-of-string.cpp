class Solution {
public:
    int partitionString(string s) {
        vector<int> a(26,0);
        int ans = 1;
        for(int i=0; i<s.size(); i++)
        {
            if(a[s[i]-'a']!=0) {
                ans++;
                for(int j=0; j<26; j++) a[j]=0;
            }
            a[s[i]-'a']++;
        }
        return ans;
    }
};