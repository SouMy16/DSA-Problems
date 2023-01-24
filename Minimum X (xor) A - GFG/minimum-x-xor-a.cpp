//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string toBinary(int n)
    {
        string ans = "";
        while(n)
        {
            ans += ('0'+n%2);
            n = n/2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int toDecimal(string s)
    {
        int ans = 0;
        for(int i=0; i<s.size(); i++)
        {
            ans += ( ( s[i] - '0' ) * ( pow( 2 , s.size() - 1 - i ) ) );
        }
        return ans;
    }
    
    int minVal(int a, int b) {
        // code here
        string s = toBinary(a);
        string bb = toBinary(b);
        int sa = 0;
        int sb = 0;
        for(int i=0; i<s.size(); i++) sa += s[i]-'0';
        for(int i=0; i<bb.size(); i++) sb += bb[i]-'0';
        
        int sz = max(s.size(), bb.size());
        string ans(sz, '0');
        
        // cout<<s<<" "<<bb<<'\n';
        // cout<<sa<<" "<<sb<<'\n';
        
        // if(sb<=sa){
        //     for(int i=0; sb>0 && i<s.size(); i++)
        //     {
        //         if(s[i] == '1')
        //         {
        //             ans[ans.size()-s.size()+i] = '1';
        //             sb--;
        //         }
        //     }
        // }
        
        // else{
        //     for(int i=s.size()-1; i>=0; i--)
        //     {
        //         ans[s.size()-1-i] = s[i];
        //         sb--;
        //     }
        //     for(int i=s.size()-1; i>=0 && sb>0; i--)
        //     {
        //         if(ans[i] == '0')
        //         {
        //             ans[i] = '1';
        //             sb--;
        //         }
        //     }
        //     while(sb>0)
        //     {
        //         ans+='1';
        //         sb--;
        //     }
        //     aa = ans;
        // }
        
        for(int i=0; sb>0 && i<s.size(); i++)
        {
            if(s[i] == '1')
            {
                ans[ans.size()-s.size()+i] = '1';
                sb--;
            }
        }
        if(sb>0)
        {
            for(int i=ans.size()-1; sb>0 and i>=0; i--)
            {
                if(ans[i]=='0')
                {
                    sb--;
                    ans[i] = '1';
                }
            }
        }
        while(sb>0)
        {
            ans += '1';
            sb--;
        }
        
        // cout<<s<<" "<<bb<<'\n';
        // cout<<sa<<" "<<sb<<'\n';
        // cout<<ans<<'\n';
        
        int answer;
        answer = toDecimal(ans);
        return answer;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends