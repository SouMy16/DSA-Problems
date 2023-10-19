class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='#') {
                if(!st.empty()) st.pop();
            }
            else st.push(s[i]);
        }
        string s1="", s2="";
        while(!st.empty()) {
            s1+=st.top();
            st.pop();
        }
        for(int i=0; i<t.size(); i++) {
            if(t[i]=='#') {
                if(!st.empty()) st.pop();
            }
            else st.push(t[i]);
        }
        // string s1="", s2="";
        while(!st.empty()) {
            s2+=st.top();
            st.pop();
        }
        // cout<<s1<<" "<<s2<<'\n';
        return s1==s2;
    }
};