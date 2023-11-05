class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mx, mxi;
        mx=arr[0], mxi=0;
        int wins = 0;
        for(int i=1; i<arr.size(); i++) {
            if(arr[i] > mx) {
                mx = arr[i];
                wins = 1;
            } else {
                wins++;
            }
            if(wins == k) return mx;
        }
        return mx;
    }
};