class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long int ans = 0;
        int n = costs.size();
        int s = candidates;
        int e = max(s, n-candidates-1);
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        for(int i=0; i<s; i++) pq1.push(costs[i]);
        for(int i=e+1; i<n; i++) pq2.push(costs[i]);
        int taken=0;
        while(taken<k)
        {
            taken++;
            int c1 = pq1.size()==0?1e6:pq1.top();
            int c2 = pq2.size()==0?1e6:pq2.top();
            if(c1<=c2)
            {
                // cout<<"c1->"<<c1<<'\n';
                ans += c1;
                pq1.pop();
                if(s<=e && s<n) 
                {
                    pq1.push(costs[s]);
                    s++;
                }
            }
            else{
                // cout<<"c2->"<<c2<<'\n';
                ans += c2;
                pq2.pop();
                if(e>=s && e>=0)
                {
                    pq2.push(costs[e]);
                    e--;
                }
            }
        }
        return ans;
    }
};