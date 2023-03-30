//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkLen(string & s, int l, int r)
    {
        while(l >= 0 && r < s.length() && s[l] == s[r]) l--, r++;
        return r - l - 1;
    }
  
    string longestPalin(string s) {
       
        int ans = 0, st = 0;
        for(int i = 0; i<s.length(); i++)
        {
            int len1 = checkLen(s, i, i);
            int len2 = checkLen(s, i , i+1);
            
            int len = max(len1, len2);
            if(len > ans)
            {
                ans = len;
                st = i - (len - 1)/2;
            }
        }
        
        return s.substr(st, ans);
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends