//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      
        map<int,int> m;
        for(int i=0; i<N; i++)
        {
            m[arr[i]] = 1;
        }
        vector<int> v;
        for(map<int,int> :: iterator it = m.begin(); it!= m.end(); it++)
        {
            v.push_back(it->first);
        }
        int cur=1, ans=1;
        for(int i=1; i<v.size(); i++)
        {
            if(v[i]-v[i-1] == 1)
            {
                cur++;
                ans = max(ans, cur);
            }
            else cur = 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends