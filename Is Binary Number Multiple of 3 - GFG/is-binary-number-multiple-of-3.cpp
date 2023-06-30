//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int ans=0;
	    for(int i=s.size()-1; i>=0; i-=2)
	    {
	        if(s[i] == '1') ans++;
	    }
	    for(int i=s.size()-2; i>=0; i-=2)
	    {
	        if(s[i] == '1') ans+=2;
	    }
	    return ans%3==0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends