class Solution {
public:
    int lisInsert(vector<int> &v, int ele)
    {
        int low = 0;
        int high = v.size();
        while(low<high)
        {
            int mid = low+(high-low)/2;
            if(v[mid] > ele) high = mid;
            else if(v[mid] <= ele) low = mid+1;
            // else return mid+1;
        }
        // ans = low;
        v[low] = ele;
        return low+1;
    }
    
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n, 0);
        ans[0] = 1;
        vector<int> v;
        v.push_back(obstacles[0]);
        for(int i=1; i<n; i++)
        {
            if(obstacles[i]>=v.back()) 
            {
                v.push_back(obstacles[i]);
                ans[i] = v.size();
            }
            else{
                ans[i] = lisInsert(v, obstacles[i]);
            } 
        }
        return ans;
    }
};