class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        sort(time.begin(), time.end());
        long long int high = time[0];
        high*=totalTrips+1;
        long long int low = 0;
        while(low<=high)
        {
            long long int mid = low + (high-low)/2;
            long long int trips = 0;
            for(int i=0; i<n; i++)
            {
                trips += (mid/time[i]);
            }
            if(trips < totalTrips) low = mid+1;
            else if(trips >= totalTrips) high = mid-1;
        }
        return low;
    }
};