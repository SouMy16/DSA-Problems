//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &a, vector<vector<int>> &q) {
        // code here
        vector<int> ans;
        vector<int> v(n,0);
        map<int,int> m;
        for(int i=n-1; i>=0; i--)
        {
            m[a[i]]++;
            v[i] = m[a[i]];
        }
        for(int i=0; i<num; i++)
        {
            int l = q[i][0];
            int r = q[i][1];
            int k = q[i][2];
            int count = 0;
            // cout<<"l="<<l<<" r="<<r<<" k="<<k<<'\n';
            for(int j=l; j<=r; j++)
            {
                if(v[j] == k) 
                {
                    // cout<<a[j]<<" "<<v[j]<<'\n';
                    count++;
                }
            }
            // cout<<endl;
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends