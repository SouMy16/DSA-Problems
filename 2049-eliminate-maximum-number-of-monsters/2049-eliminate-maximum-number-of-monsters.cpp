class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size(), ans = 0;
        priority_queue<vector<double>, vector<vector<double> >, greater<vector<double> > > pq;
        for(int i=0; i<n; i++) {
            // distance speed time
            pq.push(vector<double>{1.0*dist[i]/speed[i], 1.0*dist[i], 1.0*speed[i]});
        }
        int curt = 0;
        while(!pq.empty()) {
            int d = (int)pq.top()[1];
            int s = (int)pq.top()[2];
            // int t = (int)pq.top()[3];
            // cout<<d<<" "<<s<<" "<<'\n';
            d = d - (s*curt);
            if(d<=0) return ans;
            ans++;
            curt++;
            pq.pop();
        }
        return ans;
    }
};