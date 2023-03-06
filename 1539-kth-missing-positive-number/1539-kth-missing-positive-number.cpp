class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=1;
        for(int i=0; i<arr.size(); i++)
        {
            while(arr[i] != n)
            {
                k--;
                if(k == 0) return n;
                n++;
            }
            n++;
        }
        while(k>0)
        {
            k--;
            n++;
        }
        return n-1;
    }
};