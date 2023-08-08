//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        for(int i=0; i<n; i++){
            int num = numerator[i], den = denominator[i];
            int div = __gcd(numerator[i], denominator[i]);
            numerator[i] /= div;
            denominator[i] /= div;
        }
        map<int, map<int,int>> m;
        for(int i=0; i<n; i++){
            m[denominator[i]][numerator[i]]++;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(numerator[i] != denominator[i]-numerator[i]) ans = ans + m[denominator[i]][numerator[i]]*m[denominator[i]][denominator[i]-numerator[i]];
            else ans = ans + (m[denominator[i]][numerator[i]]*(m[denominator[i]][numerator[i]]-1))/2;
            m[denominator[i]][numerator[i]] = 0;
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
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends