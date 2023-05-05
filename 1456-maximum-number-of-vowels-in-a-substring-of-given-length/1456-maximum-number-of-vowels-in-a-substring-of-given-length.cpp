class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int cur = 0;
        int n = s.size();
        for(int i=0; i<n && i<k; i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') cur++;
        }
        ans = max(ans, cur);
        for(int i=k; i<n; i++)
        {
            i-=k;
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') cur--;
            i+=k;
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') cur++;
            ans = max(ans, cur);
        }
        return ans;
    }
};