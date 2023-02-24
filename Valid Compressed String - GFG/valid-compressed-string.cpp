//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int j = 0;
        int num = 0;
        for(int i=0; i<T.size(); i++)
        {
            if(T[i] >= '0' && T[i] <= '9')
            {
                num *= 10;
                num += T[i]-'0';
            }
            else{
                j += num;
                if(j>=S.size()) return 0;
                num = 0;
                if(T[i] != S[j]) return 0;
                j++;
            }
        }
        if(j+num != S.size()) return 0;
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends