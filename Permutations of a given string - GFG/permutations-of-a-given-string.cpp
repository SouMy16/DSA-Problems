//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void findPermutations(map<char, int> v, string cur, vector<string> &ans)
	    {
	        int f = 0;
	        for(auto e:v)
	        {
	            if(e.second > 0)
	            {
	                f = 1;
	                v[e.first]--;
	                cur += e.first;
	                findPermutations(v, cur, ans);
	                cur.pop_back();
	                v[e.first]++;
	            }
	        }
	        if(f == 0)
	        {
	           // cout<<cur<<'\n';
	            ans.push_back(cur);
	            return;
	        }
	        return;
	    }
	    
		vector<string> find_permutation(string s)
		{
		    // Code here there
		    vector<string> ans;
		    map<char, int> v;
		    for(int i=0; i<s.size(); i++)
		    {
		        v[s[i]]++;
		    }
		    findPermutations(v, "", ans);
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends