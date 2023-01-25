//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        int ans = 0;
        string ns = "";
        for(int i=s.size()-1; i>=0; i--)
        {
            if(i%2)
            {
                int mid = (i+1)/2;
                string s1 = s.substr(0,mid);
                string s2 = s.substr(mid,mid);
                // cout<<s1<<" "<<s2<<'\n';
                if(s1 == s2)
                {
                    ans += mid+1;
                    break;
                }
                else ans++;
            }
            else ans++;
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
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends