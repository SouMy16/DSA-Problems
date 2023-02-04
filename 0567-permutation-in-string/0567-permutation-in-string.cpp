class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        vector<int> m1(26,0);
        for(int i=0; i<s1.size(); i++)
        {
            m1[s1[i]-'a']++;
        }
        for(int i=0; i<s2.size(); i++)
        {
            if(m1[s2[i]-'a'] > 0)
            {
                vector<int> m2(26,0);
                for(int j=0; i+j<s2.size() && j<s1.size(); j++)
                {
                    m2[s2[i+j]-'a']++;
                }
                int f = 1;
                for(int i=0; i<26; i++)
                {
                    if(m1[i] != m2[i])
                    {
                        f = 0;
                        break;
                    }
                }
                if(f) return true;
            }
        }
        return false;
    }
};