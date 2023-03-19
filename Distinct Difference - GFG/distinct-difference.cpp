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
    vector<int> getDistinctDifference(int n, vector<int> &a) {
        // code here
        set<int> s,ss;
        int c = 0;
        vector<int> left(n), right(n);
        for(int i=0; i<n; i++)
        {
            left[i] = s.size();
            s.insert(a[i]);
        }
        
        for(int i=n-1; i>=0; i--)
        {
            right[i] = ss.size();
            ss.insert(a[i]);
        }
        
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            ans[i] = left[i]-right[i];
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
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends