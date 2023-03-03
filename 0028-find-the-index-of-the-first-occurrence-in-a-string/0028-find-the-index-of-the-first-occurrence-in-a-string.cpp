class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack==needle) return 0;
        for(int i=0;i<haystack.size();i++)
        {
            // cout<<i<<" "<<haystack[i]<<'\n';
            if(haystack[i]==needle[0] && ((i+needle.size()) < haystack.size()+2))
            {
                // cout<<"Enter at "<<i<<'\n';
                int f=0;
                for(int j=1;j<needle.size();j++)
                {
                    if(haystack[i+j]!=needle[j])
                    {
                        f=1;
                        break;
                    }
                }
                if(f==0) return i;
            }
        }
        return -1;
    }
};