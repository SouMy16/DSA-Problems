//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void nextPermutation(string &s)
    {
        int i = s.size()-1;
        for(int k=i; k>=0; k--)
        {
            if(s[k-1]<s[k])
            {
                for(int j=i; j>=k; j--)
                {
                    if(s[j]>s[k-1])
                    {
                        swap(s[k-1], s[j]);
                        break;
                    }
                }
                sort(s.begin()+k, s.end());
                break;
            }
        }
        // cout<<s<<'\n';
        return;
    }
    
    string kthPermutation(int n, int k)
    {
        // code here
        string ans = "";
        for(int i=1; i<=n; i++)
        {
            ans += ('0'+i);
        }
        for(int i=1; i<k; i++) nextPermutation(ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends