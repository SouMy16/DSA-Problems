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
    int minimumInteger(int N, vector<int> &A) {
        // code here
        int ans = INT_MAX;
        long long int S = 0;
        for(int i=0; i<N; i++) S+=A[i];
        for(int i=0; i<N; i++)
        {
            long long int cur = A[i];
            cur *= N;
            if(ans > A[i] && A[i]>=(S+N-1)/N) ans = A[i];
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
        int res = obj.minimumInteger(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends