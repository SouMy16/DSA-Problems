class Solution {
public:
    int inout[20];
    int solve(int ind, vector<vector<int>>& a)
    {
        if(ind == a.size())
        {
            for(int i=0; i<20; i++) if(inout[i] != 0) return -1e5;
            return 0;
        }
        int nottake = solve(ind+1, a);
        inout[a[ind][0]]++, inout[a[ind][1]]--;
        int take = 1+solve(ind+1, a);
        inout[a[ind][0]]--, inout[a[ind][1]]++;
        return max(take, nottake);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        for(int i=0; i<20; i++) inout[i] = 0;
        return solve(0, requests);
    }
};