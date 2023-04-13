//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string s){
        //Write your code here
        int ans = 0;
        int cur = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='0') cur--;
            else cur++;
            if(cur == 0) ans++;
        }
        if(cur != 0) return -1;
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends