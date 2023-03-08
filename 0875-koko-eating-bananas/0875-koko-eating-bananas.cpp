class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        long long int high = piles[n-1]+1;
        long long int low = 1;
        while(low<high)
        {
            long long int mid = low+(high-low)/2;
            // cout<<mid<<' ';
            long long int hours = 0;
            for(int i=0; i<n; i++)
            {
                hours += (piles[i]/mid);
                if(piles[i]%mid != 0) hours++;
            }
            // cout<<hours<<'\n';
            if(hours > h) low = mid+1;
            else if(hours <= h) high = mid;
        }
        return low;
    }
};