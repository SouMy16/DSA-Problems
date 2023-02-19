//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int n){
        // code here
        string ans = "1";
        int carry = 0;
        for(int i=1; i<=n; i++)
        {
            int carry = 0;
            for(int j = 0; j<ans.size(); j++)
            {
                int x = ans[j] - '0';
                x *= i;
                x += carry;
                ans[j] = '0'+(x%10);
                carry = x/10;
            }
            while(carry)
            {
                ans += ('0'+(carry%10));
                carry /= 10;
            }
        }
        vector<int> answer;
        for(int i=0; i<ans.size(); i++) answer.push_back(ans[i]-'0');
        // cout<<ans<<'\n';
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends