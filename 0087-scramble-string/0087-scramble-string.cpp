class Solution {
public:
    map<string, bool> m;
    bool isScramble(string s1, string s2) {
        string key = s1+" "+s2;
        if(m.find(key)!=m.end()) return m[key];
        if(s1 == s2) 
        {
            m[key] = true;
            return true;
        }
        bool ans = false;
        int n = s1.size();
        for(int i=1; i<n; i++)
        {
            string x = s1.substr(0,i);
            string y = s1.substr(i,n);
            string x1 = s2.substr(0,i);
            string y1 = s2.substr(i,n);
            string x2 = s2.substr(n-i,i);
            string y2 = s2.substr(0, n-i);
            if((isScramble(x,x1)&&isScramble(y,y1)))
            {
                m[key] = true;
                return true;
            }
            if((isScramble(x,x2)&&isScramble(y,y2)))
            {
                m[key] = true;
                return true;
            }
        }
        m[key] = false;
        return false;
    }
};