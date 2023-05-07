//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            //code here
            int ans = 0;
            vector<int> v(s.size(), 1);
            for(int i=1; i<v.size(); i++)
            {
                v[i] = v[i-1]*2;
                v[i] %= m;
            }
            for(int i=0; i<s.size(); i++)
            {
                if(s[i] == '1') ans += v[s.size()-1-i];
                ans %= m;
            }
            ans %= m;
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends