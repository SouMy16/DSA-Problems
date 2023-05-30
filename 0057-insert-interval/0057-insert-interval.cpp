class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int f = 0;
        for(int i=0; i<n; i++)
        {
            if(intervals[i][1] >= newInterval[0] && intervals[i][0] <= newInterval[1])
            {
                int j = i;
                while(j<n && newInterval[1] >= intervals[j][0]) j++;
                j--;
                vector<int> v(2, 0);
                v[0] = min(intervals[i][0], newInterval[0]);
                v[1] = max(intervals[j][1], newInterval[1]);
                ans.push_back(v);
                i = j;
                f = 1;
            }
            else if(f == 0 && intervals[i][0] > newInterval[0])
            {
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                f = 1;
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        if(f == 0) ans.push_back(newInterval);
        return ans;
    }
};