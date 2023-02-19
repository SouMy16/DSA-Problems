//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long int product = 1;
	    long long int ans = arr[0];
	    long long int first = 0;
	    for(int i=0; i<n; i++)
	    {
	        product *= arr[i];
	        ans = max(ans, product);
	        if(product == 0) product = 1, first = 0;
	        if(product < 0 && first == 0) first = product;
	        else if(product < 0 && first < 0) ans = max(ans, (product/first));
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends