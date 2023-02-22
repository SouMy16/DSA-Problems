class Solution {
public:
    int shipWithinDays(vector<int>& a, int days) {
        int low=a[0],high=0;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            low = min(low, a[i]);
            high += a[i];
        }
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int cur = 1;
            int sum = 0;
            int f = 0;
            for(int i=0; i<n; i++)
            {
                if(sum+a[i] <= mid) sum+=a[i];
                else if(a[i] > mid){
                    f = 1;
                    break;
                }
                else {
                    sum = a[i];
                    cur++;
                }
            }
            if(f) low = mid + 1;
            else if(cur<=days) high = mid-1;
            else if(cur>days) low = mid+1;
        }
        return low;
    }
};