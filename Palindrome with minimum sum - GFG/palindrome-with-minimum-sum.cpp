//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        int n = s.size();
        for(int i=0; i<n/2; i++)
        {
            if(s[i]!='?' && s[i]!=s[n-1-i] && s[n-1-i]!='?') return -1;
        }
        string ans = s;
        for(int i=0; i<n; i++)
        {
            if(ans[i]=='?' && ans[n-1-i]!='?') ans[i] = ans[n-1-i];
            // if(ans[i]=='?' && ans[n-1-i]=='?' && i>0) ans[i] = ans[i-1];
        }
        for(int i=0; i<n; i++)
        {
            if(ans[i]!='?')
            {
                for(int j=i-1; j>=0; j--)
                {
                    if(ans[j]!='?') break;
                    ans[j] = ans[i];
                    ans[n-1-j] = ans[i];
                }
            }
        }
        for(int i=0; i<n; i++) if(ans[i] == '?') ans[i] = 'a';
        // cout<<ans<<'\n';
        int answer = 0;
        for(int i=1; i<n; i++)
        {
            answer += abs(ans[i]-ans[i-1]);
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends