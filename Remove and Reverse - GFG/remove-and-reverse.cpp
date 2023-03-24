//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
        vector<int> v(26,0);
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            v[s[i]-'a']++;
        }
        int ltr = 1;
        int f = 0;
        for(int i=0; i<26; i++) if(v[i]>1) f=1;
        int i = 0;
        int j = n-1;
        while(f)
        {
            if(ltr == 1)
            {
                ltr = 0;
                for(; i<=j; i++)
                {
                    if(s[i]!='#' && v[s[i]-'a'] > 1){
                        v[s[i]-'a']--;
                        s[i] = '#';
                        break;
                    }
                }
            }
            else{
                ltr = 1;
                for(; j>=i; j--)
                {
                    if(s[j]!='#' && v[s[j]-'a'] > 1){
                        v[s[j]-'a']--;
                        s[j] = '#';
                        break;
                    }
                }
            }
            f=0;
            for(int i=0; i<26; i++) if(v[i]>1) f=1;
        }
        string ans = "";
        for(int i=0; i<s.size(); i++) if(s[i]!='#') ans+=s[i];
        if(ltr==1) return ans;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends