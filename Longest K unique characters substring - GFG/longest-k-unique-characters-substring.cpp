//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        set<char> st;
        vector<int> vec(26, 0);
        int start=0;
        st.insert(s[0]);
        vec[s[0]-'a'] = 1;
        int ans = -1;
        for(int i=1; i<s.size(); i++) {
            st.insert(s[i]);
            // cout<<i<<" "<<st.size();
            vec[s[i]-'a']++;
            while(st.size() > k) {
                vec[s[start]-'a']--;
                if(vec[s[start]-'a'] == 0) {
                    st.erase(st.find(s[start]));
                }
                start++;
            }
            // cout<<" "<<st.size()<<'\n';
            if(st.size() == k) ans = max(ans, i-start+1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends