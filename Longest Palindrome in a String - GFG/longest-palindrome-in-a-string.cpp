//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int n = s.size(); 
        string ans = "";
        int len = 0;
        for(int i=0; i<n; i++)
        {
            int j = 0;
            while(i-j>=0 && i+j<n && s[i-j] == s[i+j]) j++;
            j--;
            if(2*j+1 > len)
            {
                len = 2*j+1;
                ans = s.substr(max(0, i-j), len);
            }
            j = 0;
            while(i-1-j>=0 && i+j<n && s[i-1-j] == s[i+j]) j++;
            j--;
            if(2*(j+1) > len)
            {
                len = 2*(j+1);
                ans = s.substr(max(0, i-j-1), len);
            }
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
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends