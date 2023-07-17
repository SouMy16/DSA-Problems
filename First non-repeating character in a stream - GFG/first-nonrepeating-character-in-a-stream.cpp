//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    vector<int> ind(26, -1);
		    string ans = "";
		    for(int i=0; i<s.size(); i++)
		    {
		        if(ind[s[i]-'a'] == -1)
		        {
		            ind[s[i]-'a'] = i;
		        }
		        else{
		            ind[s[i]-'a'] = -2;
		        }
		        int cur = INT_MAX;
		        char c = '#';
		        for(int j=0; j<26; j++)
		        {
		            if(ind[j] < 0) continue;
		            if(ind[j] < cur)
		            {
		                cur = ind[j];
		                c = 'a'+j;
		            }
		        }
		        ans += c;
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends