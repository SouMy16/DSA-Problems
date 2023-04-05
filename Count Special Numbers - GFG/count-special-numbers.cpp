//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> a) {
        // Code here
        map<int,int> m;
        for(int i=0; i<n; i++) m[a[i]]++;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(m[a[i]]>1)
            {
                ans++;
                continue;
            }
            for(auto ele: m)
            {
                if(ele.first != a[i] && a[i]%(ele.first) == 0)
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends