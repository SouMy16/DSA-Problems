//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    string
nextPermutation (string s)
{
  int f = 0;
  for (int i = s.size () - 2; i >= 0; i--)
    {
      if (s[i] < s[i + 1])
	{
	  sort (s.begin () + (i+1), s.end ());
	  for(int j=i+1; j<s.size(); j++)
	  {
	      if(s[j]>s[i]) {swap(s[i], s[j]); break;}
	  }
	  f = 1;
	  break;
	}
    }
  if (f == 0)
    sort (s.begin (), s.end ());
//   cout<<s<<'\n';

  return s;
}

vector<string> find_permutation (string s)
{
  vector < string > ans;
  sort (s.begin (), s.end ());
  string ss = s;
  ans.push_back (ss);
  ss = nextPermutation (ss);
  while (ss != s)
    {
      ans.push_back (ss);
      string temp = nextPermutation (ss);
      if (temp == ss)
	break;
      ss = temp;
    }
  return ans;
    // for(int i=0; i<ans.size(); i++)
    // {
    //     cout<<ans[i]<<'\n';
    // }
    // return;
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