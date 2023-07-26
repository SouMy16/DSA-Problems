class Solution {
public:
    bool check(vector<int> &a, double hour, int m)
    {
        double time = 0.0;
        for(int i=0; i<a.size()-1; i++)
        {
            time += (a[i]+m-1) / m;
        }
        time += 1.0*a[a.size()-1]/m;
        return time<=hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int mx = 0;
        for(int i=0; i<dist.size(); i++) mx = max(mx, dist[i]);
        int low = 1, high = 1e7+9;
        int ans = -1;
        while(low < high)
        {
            int mid = low + (high-low)/2;
            if(check(dist, hour, mid))
            {
                ans = mid;
                high = mid;
            }
            else low = mid+1;
        }
        return ans;
    }
};