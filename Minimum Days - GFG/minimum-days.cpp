//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int n, string s, vector<int> &p) {
        // code here
        int ans = 0;
        set<int> st;
        for(int i=0; i<n; i++)
        {
            if(s[i] == s[i+1]) 
            {
                st.insert(i);
                st.insert(i+1);
            }
        }
        if(st.empty()) return ans;
        for(int i=0; i<n; i++)
        {
            if(p[i]>=2 && s[p[i]-1] == s[p[i]] && s[p[i]] == s[p[i]-2]) st.erase(p[i]);
            else if(s[p[i]] == s[p[i]-1])
            {
                st.erase(p[i]);
                st.erase(p[i]-1);
            }
            
            if(p[i]<n-2 && s[p[i]] == s[p[i]+1] && s[p[i]+2] == s[p[i]]) st.erase(p[i]);
            else if(s[p[i]] == s[p[i]+1])
            {
                st.erase(p[i]);
                st.erase(p[i]+1);
            }
            s[p[i]] = '?';
            if(st.empty())
            {
                ans = i+1;
                break;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends