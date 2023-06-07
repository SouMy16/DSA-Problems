class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        int i=0;
        int mx = max(a, max(b, c));
        while(1<<i <= mx)
        {
            // cout<<(a>>i)<<" "<<(b>>i)<<" "<<(c>>i)<<" "<<'\n';
            if((c>>i)&1 == 1)
            {
                if((a>>i)&1 == 1 || (b>>i)&1 == 1)
                {
                    i++;
                    continue;
                }
                else ans++;
            }
            else{
                if((a>>i)&1 == 1) ans++;
                if((b>>i)&1 == 1) ans++;
            }
            i++;
        }
        return ans;
    }
};