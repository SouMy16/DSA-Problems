//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void findPermutations(string &s, string cur, vector<string> &ans){
        if(cur.size() == s.size()){
            ans.push_back(cur);
            return;
        }
        for(int i=0; i<s.size(); i++){
            if(s[i] != '#'){
                char temp = s[i];
                s[i] = '#';
                cur += temp;
                findPermutations(s, cur, ans);
                cur.pop_back();
                s[i] = temp;
            }
        }
        return;
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        string cur = "";
        findPermutations(S, cur, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends