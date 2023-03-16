//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int sum, int d){
        // code here 
        if(sum>=9*d) return "-1";
        string ans = "1";
        for(int i=1; i<d; i++) ans+="0";
        sum -= 1;
        int i = ans.size()-1;
        while(sum>0 && i>=0)
        {
            if(sum >= 9) 
            {
                ans[i] = '9';
                sum -= 9;
            }else{
                ans[i] = (ans[i]-'0')+sum+'0';
                sum = 0;
            }
            i--;
        }
        // cout<<ans<<'\n';
        for(int i=ans.size()-1; i>0; i--)
        {
            if(ans[i]>ans[i-1])
            {
                ans[i] = ((ans[i]-'0')-1)+'0';
                ans[i-1] = ((ans[i-1]-'0')+1)+'0';
                break;
            }
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends