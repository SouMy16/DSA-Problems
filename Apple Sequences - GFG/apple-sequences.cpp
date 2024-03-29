//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            if(arr[i] == 'O') v.push_back(i+1);
        }
        if(v.size() <= m) return n;
        int ans = v[m]-1;
        for(int i = m; i<v.size()-1; i++)
        {
            ans = max(ans, v[i+1]-v[i-m]-1);
        }
        ans = max(ans, n-v[v.size()-1-m]);
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
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends