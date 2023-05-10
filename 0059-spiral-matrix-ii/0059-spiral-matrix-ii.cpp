class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int cur=0;
        int rs=0, re=n-1, cs=0, ce=n-1;
        while(rs<=re && cs<=ce)
        {
            for(int i=cs; i<=ce; i++) ans[rs][i] = ++cur;
            rs++;
            for(int i=rs; i<=re; i++) ans[i][ce] = ++cur;
            ce--;
            if(!(rs<=re && cs<=ce)) break;
            for(int i=ce; i>=cs; i--) ans[re][i] = ++cur;
            re--;
            for(int i=re; i>=rs; i--) ans[i][cs] = ++cur;
            cs++;
        }
        return ans;
    }
};