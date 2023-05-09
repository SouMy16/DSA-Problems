class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rs=0, cs=0, re=matrix.size(), ce=matrix[0].size();
        while(rs<re && cs<ce)
        {
            for(int i=cs; i<ce; i++) ans.push_back(matrix[rs][i]);
            rs++;
            for(int i=rs; i<re; i++) ans.push_back(matrix[i][ce-1]);
            ce--;
            if(!(rs<re && cs<ce)) break;
            for(int i=ce-1; i>=cs; i--) ans.push_back(matrix[re-1][i]);
            re--;
            for(int i=re-1; i>=rs; i--) ans.push_back(matrix[i][cs]);
            cs++;
        }
        return ans;
    }
};