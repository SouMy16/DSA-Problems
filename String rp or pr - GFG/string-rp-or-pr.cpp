//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S){
      //code here
      if(S.size()<2) return 0;
      long long int ans = 0;
      
      if(X>=Y)
      {
          // remove pr first
          string s = "";
          s+=S[0];
          for(int i=1; i<S.size(); i++)
          {
              s += S[i];
              if(s[s.size()-1]=='r' && s[s.size()-2]=='p')
              {
                  ans += X;
                  s.pop_back();
                  s.pop_back();
              }
          }
          if(s.size()<2) return ans;
          string c = "";
          c+=s[0];
          for(int i=1; i<s.size(); i++)
          {
              c += s[i];
              if(c[c.size()-1]=='r' && c[c.size()-2]=='p')
              {
                  ans += X;
                  c.pop_back();
                  c.pop_back();
              }
              else if(c[c.size()-1]=='p' && c[c.size()-2]=='r')
              {
                  ans += Y;
                  c.pop_back();
                  c.pop_back();
              }
          }
          if(c.size() == S.size()) return ans;
          ans += solve(X, Y, c);
      }
      else{
          // remove rp first
          string s = "";
          s+=S[0];
          for(int i=1; i<S.size(); i++)
          {
              s += S[i];
              if(s[s.size()-1]=='p' && s[s.size()-2]=='r')
              {
                  ans += Y;
                  s.pop_back();
                  s.pop_back();
              }
          }
          if(s.size()<2) return ans;
          string c = "";
          c+=s[0];
          for(int i=1; i<s.size(); i++)
          {
              c += s[i];
              if(c[c.size()-1]=='p' && c[c.size()-2]=='r')
              {
                  ans += Y;
                  c.pop_back();
                  c.pop_back();
              }
              else if(c[c.size()-1]=='r' && c[c.size()-2]=='p')
              {
                  ans += X;
                  c.pop_back();
                  c.pop_back();
              }
          }
          if(c.size() == S.size()) return ans;
          ans += solve(X, Y, c);
      }
      return ans;
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends