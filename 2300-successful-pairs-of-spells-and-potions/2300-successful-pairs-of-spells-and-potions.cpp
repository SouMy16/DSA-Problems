class Solution {
public:
    int BinSea(vector<int> &a, long long int x, long long int m)
    {
        int low = 0;
        int high = a.size(); 
        while(low<high)
        {
            int mid = low+(high-low)/2;
            long long int p = a[mid];
            p*=m;
            if(p>=x) high = mid;
            else low = mid+1;
        }
        return a.size()-low;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());
        for(int i=0; i<n; i++)
        {
            // long long int minreq = (success+spells[i]-1)/spells[i];
            ans[i] = BinSea(potions, success, spells[i]);
        }
        return ans;
    }
};