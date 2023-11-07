class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size(), ans = 0;
        vector<double> arrivalTime;
        for(int i=0; i<n; i++) {
            arrivalTime.push_back(1.0*dist[i]/speed[i]);
        }
        sort(arrivalTime.begin(), arrivalTime.end());
        for(int i=0; i<n; i++) {
            if(arrivalTime[i] > i) ans++;
            else break;
        }
        return ans;
    }
};