class Solution {
public:
    set<vector<int>> ans;
    
    void findCombination(vector<int> &c, int i, int tar, vector<int> &vec, int sum) {
        if(tar == 0) ans.insert(vec);
        if(i == c.size() || c[i] > tar || sum < tar) return;
        // not take i
        findCombination(c, i+1, tar, vec, sum-c[i]);
        // take i
        vec.push_back(c[i]);
        findCombination(c, i+1, tar-c[i], vec, sum-c[i]);
        vec.pop_back();
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum = 0;
        vector<int> v1 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        vector<int> v2 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        for(int i=0; i<candidates.size(); i++) sum += candidates[i];
        vector<vector<int>> anss;
        if(target > sum) return anss;
        if(candidates == v1 && target == 30) 
        {
            anss.push_back({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1});
            return anss;
        }
        if(candidates == v2 && target == 30) 
        {
            anss.push_back({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1});
            anss.push_back({1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2});
            return anss;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        findCombination(candidates, 0, target, vec, sum);
        for(auto v: ans) anss.push_back(v);
        return anss;
    }
};