//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        // code here
        int u = 0;
        int l = 0;
        int n = s.size();
        map<int,int> m;
        int c=0;
        m[0] = 1;
        int ans = 0;
        for(int i=0; i<n; i++) 
        {   if(s[i]>='A' && s[i]<='Z')
            {
                c++;
            }
            else c--;
            ans += m[c];
            m[c]++;
        }
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends