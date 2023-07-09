class Solution {
public:
    int largestVariance(string s) {
        int c1=0, c2=0;
        int ans = 0;
        for(int ch1=0; ch1<26; ch1++)
        {
            for(int ch2=0; ch2<26; ch2++)
            {
                if(ch1 == ch2) continue;
                for(int k=0; k<2; k++)
                {
                    c1=0, c2=0;
                    for(int i=0; i<s.size(); i++)
                    {
                        if((s[i]-'a') == ch1) c1++;
                        else if((s[i]-'a') == ch2) c2++;
                        
                        if(c2>c1) c1=0, c2=0;
                        else{
                            if(c1>0 && c2>0) 
                            {
                                // cout<<(char)('a'+ch1)<<" "<<(char)('a'+ch2)<<" "<<ans<<'\n';
                                ans = max(ans, c1-c2);
                            }
                        }
                    }
                    reverse(s.begin(), s.end());
                }
            }
        }
        return ans;
    }
};