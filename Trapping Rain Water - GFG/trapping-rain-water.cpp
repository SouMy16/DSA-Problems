//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> lm(n, 0), rm(n, 0);
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            // if(st.empty()) st.push(arr[i]);
            // else {
                while(!st.empty() && st.top()<=arr[i]) st.pop();
                if(!st.empty()) lm[i] = st.top();
                else st.push(arr[i]);
            // }
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && st.top()<arr[i]) st.pop();
            if(!st.empty()) rm[i] = st.top();
            else st.push(arr[i]);
        }
        
        long long int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans += max(0,min(lm[i], rm[i])-arr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends