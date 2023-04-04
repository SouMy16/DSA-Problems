//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int evaluate(int i, int j, string &s, bool toEvaluate, vector<vector<vector<int>>> &dp)
    {
        if(i>j) return 0;
        if(i==j)
        {
            if(s[i]=='T' && toEvaluate==true) return 1;
            else if(s[i]=='F' && toEvaluate==false) return 1;
            return 0;
        }
        vector<int> v = vector<int>{i, j, toEvaluate==true?1:0};
        int f = 0;
        if(toEvaluate) f = 1;
        if(dp[i][j][f] != -1) return dp[i][j][f]%1003;
        int ans = 0;
        for(int k=i+1; k<=j-1; k+=2)
        {
            int lt=0, lf=0, rt=0, rf=0;
            lt = evaluate(i, k-1, s, true, dp);
            lf = evaluate(i, k-1, s, false, dp);
            rt = evaluate(k+1, j, s, true, dp);
            rf = evaluate(k+1, j, s, false, dp);
            if(toEvaluate==true)
            {
                if(s[k]=='|')
                {
                    ans += ((lt*rt) + (lf*rt) + (lt*rf));
                }
                else if(s[k]=='&')
                {
                    ans += (lt*rt);
                }
                else if(s[k]=='^')
                {
                    ans += ((lt*rf) + (lf*rt));
                }
            }
            else if(toEvaluate == false)
            {
                if(s[k]=='|')
                {
                    ans += (lf*rf);
                }
                else if(s[k]=='&')
                {
                    ans += ((lf*rf) + (lf*rt) + (lt*rf));
                }
                else if(s[k]=='^')
                {
                    ans += ((lt*rt) + (lf*rf));
                }
            }
        }
        dp[i][j][f] = ans%1003;
        return ans%1003;
    }
    
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(2,-1)));
        evaluate(0, N-1, S, true, dp);
        // cout<<dp[0][N-1][1];
        return evaluate(0, N-1, S, true, dp);
        // return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends