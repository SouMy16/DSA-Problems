class Solution {
public:
    int solve(int ind, int diff, vector<int> &a, map<int, map<int, int>> &m)
    {
        if(ind == a.size())
        {
            if(diff == 0) return m[ind][diff] = 0;
            return INT_MIN;
        }
        if(m[ind].find(diff) != m[ind].end()) return m[ind][diff];
        int op1, op2, op3;
        op1 = solve(ind+1, diff, a, m);
        op2 = a[ind]+solve(ind+1, diff+a[ind], a, m);
        op3 = solve(ind+1, diff-a[ind], a, m);
        return m[ind][diff] = max(op1, max(op2, op3));
    }
    int tallestBillboard(vector<int>& rods) {
        map<int, map<int, int>> m;
        return solve(0, 0, rods, m);
    }
};