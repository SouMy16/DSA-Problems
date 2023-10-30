//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int zero = 0;
	    for(int i=0; i<n; i++) {
	        if(arr[i] == 0) zero++;
	        else {
	            arr[i-zero] = arr[i];
	        }
	       // for(int j=0; j<n; j++) cout<<arr[j]<<" ";
	       // cout<<'\n';
	    }
	    for(int i=n-zero; i<n; i++) arr[i] = 0;
	    return;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends