//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string ans = "";
            stack<string> st;
            string cur = "";
            for(int i=0; i<s.size(); i++)
            {
                if(s[i]>='0' && s[i]<='9') cur += s[i];
                else{
                    st.push(cur);
                    cur = "";
                    cur += s[i];
                    st.push(cur);
                    cur = "";
                }
            }
            st.push(cur);
            while(!st.empty())
            {
                ans += st.top();
                st.pop();
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends