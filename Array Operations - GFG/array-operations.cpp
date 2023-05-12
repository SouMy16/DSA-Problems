//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int ans = 0;
        int cur = 0;
        int z = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] != 0) cur++;
            else z=1;
            if(cur !=0 && arr[i] == 0)
            {
                cur = 0;
                ans++;
            }
            
        }
        if(cur!=0) ans++;
        if(z==0) return -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends