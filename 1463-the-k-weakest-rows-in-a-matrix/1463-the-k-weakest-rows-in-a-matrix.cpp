class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<vector<int>, int> > pq;
        vector<int> ans;
        for(int i=0; i<mat.size(); i++) {
            pq.push({mat[i], i});
            while(pq.size()>k) pq.pop();
        }
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};