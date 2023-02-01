class Solution {
public:
    bool Divides(string &s, string &t)
    {
        if(s == t) return true;
        string cur = t;
        while(cur.size() < s.size())
        {
            // cout<<cur<<" ";
            cur += t;
        }
        if(cur == s) return true;
        return false;
    }
    
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        string s = "";
        int n = str1.size();
        int m = str2.size();
        if(n<m)
        {
            string cur = str1;
            str1 = str2;
            str2 = cur;
            n = str1.size();
            m = str2.size();
        }
        // cout<<str1<<" "<<str2<<'\n';
        if(str1.substr(0, m) != str2) return "";
        for(int i=0; i<m; i++)
        {
            s += str2[i];
            if(Divides(str1, s) && Divides(str2, s)) ans = s;
        }
        // cout<<s<<'\n';
        return ans;
    }
};