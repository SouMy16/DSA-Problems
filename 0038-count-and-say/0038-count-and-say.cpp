class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i=1; i<n; i++)
        {
            string curstr = "";
            int cur = 1;
            for(int j=1; j<ans.size(); j++)
            {
                if(ans[j] != ans[j-1])
                {
                    curstr += '0'+cur;
                    curstr += ans[j-1];
                    cur = 1;
                }
                else cur++;
            }
            curstr += '0'+cur;
            curstr += ans[ans.size()-1];
            ans = curstr;
            // cout<<i<<" "<<curstr<<'\n';
        }
        return ans;
    }
};