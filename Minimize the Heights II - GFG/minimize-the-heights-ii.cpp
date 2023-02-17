// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int a[], int n, int k) {
        // code here
        sort(a, a+n);
        int i=0;
        int ans = a[n-1] - a[0];
        for(int j=0; j<n-1; j++)
        {
            if(a[j+1] < k) continue;
            int lmax = a[j]+k;
            int lmin = a[0]+k;
            int rmax = a[n-1]-k;
            int rmin = a[j+1]-k;
            ans = min(ans, max(lmax, rmax) - min(lmin, rmin));
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends