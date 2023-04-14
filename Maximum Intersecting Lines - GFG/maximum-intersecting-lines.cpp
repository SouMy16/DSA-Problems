//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
static bool mycomp(vector<int> a, vector<int> b)
{
    if(a[1]!=b[1]) return a[1]<b[1];
    return a[0]<b[0];
}
class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        // int ans = 0;
        // sort(lines.begin(), lines.end(), mycomp);
        // for(int i=0; i<N; i++)
        // {
        //     int p = lines[i][1];
        //     int f = 0;
        //     for(int j=i; j<N; j++)
        //     {
        //         if(lines[j][0] <= p)
        //         {
        //             f++;
        //         }
        //     }
        //     ans = max(ans, f);
        // }
        map<int,int> m;
        for(int i=0; i<N; i++)
        {
            m[lines[i][0]]++;
            m[lines[i][1]+1]--;
        }
        int ans = 0;
        int cur = 0;
        for(auto it: m)
        {
            cur += it.second;
            ans = max(ans, cur);
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
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends