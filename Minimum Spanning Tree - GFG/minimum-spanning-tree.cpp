//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU
{
    private:
    vector<int> par, sze;
    public:
    DSU(int n)
    {
        par.resize(n, 0);
        sze.resize(n, 1);
        for(int i=0; i<n; i++) par[i] = i;
    }
    int findPar(int u)
    {
        if(u == par[u]) return u;
        return par[u] = findPar(par[u]);
    }
    void Union(int u, int v)
    {
        int paru = findPar(u), parv = findPar(v);
        if(paru == parv) return;
        if(sze[paru] >= sze[parv])
        {
            par[parv] = paru;
            sze[paru] += sze[parv];
        }
        else{
            par[paru] = parv;
            sze[parv] += sze[paru];
        }
        return;
    }
};



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // Prim's Algorithm
        
        // vector<vector<pair<int,int>>> g(n);
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<adj[i].size(); j++)
        //     {
        //         g[i].push_back({adj[i][j][1], adj[i][j][0]});
        //     }
        // }
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // pq.push({0, 0});
        // int ans = 0;
        // vector<int> vis(n, 0);
        // while(!pq.empty())
        // {
        //     int cur = pq.top().second;
        //     int w = pq.top().first;
        //     pq.pop();
        //     if(vis[cur] == 1) continue;
        //     else {
        //         vis[cur] = 1;
        //         ans += w;
        //     }
        //     for(int i=0; i<g[cur].size(); i++) if(!vis[g[cur][i].second]) pq.push(g[cur][i]);
        // }
        
        
        
        
        
        
        // Kruskal's Algorithm
        
        vector<vector<int>> v;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<adj[i].size(); j++)
            {
                vector<int> cur;
                cur.push_back(adj[i][j][1]);
                cur.push_back(i);
                cur.push_back(adj[i][j][0]);
                v.push_back(cur);
            }
        }
        sort(v.begin(), v.end());
        DSU d(n);
        int ans = 0;
        for(int i=0; i<v.size(); i++)
        {
            if(d.findPar(v[i][1]) != d.findPar(v[i][2]))
            {
                ans += v[i][0];
                d.Union(v[i][1], v[i][2]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends