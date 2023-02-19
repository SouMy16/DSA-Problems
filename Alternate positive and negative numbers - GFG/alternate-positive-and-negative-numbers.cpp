//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int nn) {
	   vector<int> pos,neg;
	   for(int i=0; i<nn; i++)
	   {
	       if(arr[i] >= 0) pos.push_back(arr[i]);
	       else neg.push_back(arr[i]);
	   }
	   int p=0, n=0, i=0;
	   while(p<pos.size() && n<neg.size())
	   {
	       arr[i++] = pos[p++];
	       arr[i++] = neg[n++];
	   }
	   while(p<pos.size()) arr[i++] = pos[p++];
	   while(n<neg.size()) arr[i++] = neg[n++];
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
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends