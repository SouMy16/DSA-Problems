class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size() > s.size()) return ans;
        vector<int> pc(26,0), sc(26,0);
        for(int i=0; i<p.size(); i++)
        {
            pc[p[i]-'a']++;
            sc[s[i]-'a']++;
        }
        int f = 1;
        for(int i=0; i<26; i++)
        {
            if(pc[i] != sc[i]) {f=0;break;}
        }
        if(f) ans.push_back(0);
        for(int i=p.size(); i<s.size(); i++)
        {
            sc[s[i-p.size()]-'a']--;
            sc[s[i]-'a']++;
            int f = 1;
            for(int j=0; j<26; j++)
            {
                if(pc[j] != sc[j]) {f=0;break;}
            }
            if(f) ans.push_back(i+1-p.size());
        }
        return ans;
    }
};