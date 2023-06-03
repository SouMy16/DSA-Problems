class Solution {
public:
    int height(int cur, vector<vector<int>> &child, vector<int> &infoT)
    {
        int mx = 0;
        for(int i=0; i<child[cur].size(); i++)
        {
            mx = max(mx, height(child[cur][i], child, infoT));
        }
        return mx + infoT[cur];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        vector<vector<int>> child(n);
        for(int i=0; i<n; i++)
        {
            if(i!=headID) child[manager[i]].push_back(i);
        }
        return height(headID, child, informTime);
    }
};