//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            set<int> s;
            int p1=0, p2=0, p3=0;
            while(p1<n1 && p2<n2 && p3<n3)
            {
                if(a[p1] == b[p2] && a[p1] == c[p3]) 
                {
                    s.insert(a[p1]);
                    p1++, p2++, p3++;
                }
                else if(a[p1] == min(a[p1], min(b[p2], c[p3]))) p1++;
                else if(b[p2] == min(a[p1], min(b[p2], c[p3]))) p2++;
                else if(c[p3] == min(a[p1], min(b[p2], c[p3]))) p3++;
            }
            vector<int> ans;
            for(auto& ele:s) ans.push_back(ele);
            return ans;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends