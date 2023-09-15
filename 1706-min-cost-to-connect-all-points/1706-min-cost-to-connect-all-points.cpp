class DSU {
    public:
    int sz; 
    vector<int> v, par;
    DSU(int n) {
        sz = n;
        v.resize(n);
        par.resize(n);
        for(int i=0; i<n; i++) {
            v[i] = 1;
            par[i] = i;
        }
    }

    int findPar(int n) {
        if(par[n] == n) return n;
        return findPar(par[n]);
    }

    void connect(int u, int vv) {
        if(findPar(u) == findPar(vv)) return;
        int paru = findPar(u);
        int parv = findPar(vv);
        if(v[paru] > v[parv]) {
            v[paru] += v[parv];
            par[parv] = paru;
        }
        else{
            v[parv] += v[paru];
            par[paru] = parv;
        }
        return;
    }

    bool sameComponent(int u, int vv) {
        if(findPar(u) == findPar(vv)) return true;
        return false;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        int ans = 0;
        int n = points.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                pq.push({dist, {i, j}});
            }
        }
        DSU d(n);

        while(!pq.empty()) {
            int dist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(d.sameComponent(i, j)) {
                continue;
            }
            d.connect(i, j);
            // cout<<"Connected: "<<i<<" "<<j<<'\n';
            ans += dist;
        }
        return ans;
    }
};