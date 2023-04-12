class Solution {
public:
    string simplifyPath(string path) {
        string cur = "";
        string ans = "/";
        stack<string> st, st2;
        path += '/';
        for(int i=0; i<path.size(); i++)
        {
            if(path[i]=='/')
            {
                if(cur == "..") {if(!st.empty()) st.pop();}
                else if(cur == "." || cur=="") {}
                else st.push(cur);
                cur = "";
            }
            else{
                cur += path[i];
            }
        }
        // stack<string> st2;
        while(!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }
        while(!st2.empty())
        {
            ans += st2.top();
            ans += "/";
            st2.pop();
        }
        if(ans.size()>1) ans.pop_back();
        return ans;
    }
};