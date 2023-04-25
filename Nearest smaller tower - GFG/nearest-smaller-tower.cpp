//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        vector<int> ans(arr.size(), 0);
        stack<pair<int,int>> st1, st2;
        for(int i=0; i<arr.size(); i++)
        {
            while(!st1.empty() && st1.top().first >= arr[i]) st1.pop();
            if(!st1.empty()) ans[i] = st1.top().second;
            else ans[i] = -1;
            st1.push({arr[i], i});
        }
        for(int i=arr.size()-1; i>=0; i--)
        {
            while(!st2.empty() && st2.top().first >= arr[i]) st2.pop();
            if(!st2.empty() && ans[i] == -1) ans[i] = st2.top().second;
            else if(!st2.empty() && i-ans[i] > st2.top().second-i) ans[i] = st2.top().second;
            else if(!st2.empty() && i-ans[i] == st2.top().second-i && st2.top().first < arr[ans[i]]) ans[i] = st2.top().second;
            // else ans[i] = -1;
            st2.push({arr[i], i});
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends