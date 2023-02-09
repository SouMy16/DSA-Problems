//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int ans = 0;
        map<char, int> m;
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            m[s[i]-'a']++;
        }
        int b = m[1];
        int a = m[0];
        int l = m[11];
        int o = m[14];
        int nn = m[13];
        
        return min(b, min(a, min(l/2, min(o/2, nn))));
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends