class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<vector<int>, int> > v;
        for(int i=0; i<mat.size(); i++) {
            v.push_back({mat[i], i});
        }
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};