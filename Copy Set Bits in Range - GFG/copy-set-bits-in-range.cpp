//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    void toBinStr(string &ans, int n)
    {
        if(n==0) ans = "0";
        while(n)
        {
            ans += '0'+n%2;
            n/=2;
        }
        return;
    }
    
    int toInt(string s)
    {
        int ans = 0;
        for(int i=0; i<32; i++)
        {
            if(s[i] == '1') ans += pow(2, i);
        }
        return ans;
    }
    
    int setSetBit(int x, int y, int l, int r){
        // code here
        string xs = "", ys = "";
        toBinStr(xs, x);
        toBinStr(ys, y);
        for(int i=xs.size(); i<32; i++) xs+='0';
        for(int i=ys.size(); i<32; i++) ys+='0';
        l--, r--;
        for(int i=l; i<=r; i++) if(ys[i] == '1') xs[i] = '1';   
        int ans = toInt(xs);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends