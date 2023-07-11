//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends
class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {
       //Your code here
        long long int ans = 1LL*N;
        long long int p = 1;
        // long long int mod = 1000000007;
        map<long long int, long long int> m;
        m[1] = N;
        while(p<R)
        {
            if(p*2 <= R)
            {
                p*=2;
                ans = (ans*ans)%mod;
                m[p] = ans;
            }
            else{
                for(auto po:m)
                {
                    if(p+po.first <= R)
                    {
                        ans *= po.second;
                        ans %= mod;
                        p+=po.first;
                        if(p == R) break;
                    }
                }
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends