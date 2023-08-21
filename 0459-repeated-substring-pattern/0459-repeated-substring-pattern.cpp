class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string cur = "";
        for(int i=0; i<s.size()-1; i++) {
            cur += s[i];
            int n = s.size()/cur.size();
            if(s.size() % cur.size() != 0) continue;
            string c = "";
            while(n--) {
                c += cur;
            }
            if(c == s) {
                return true;
            }
        }
        return false;
    }
};