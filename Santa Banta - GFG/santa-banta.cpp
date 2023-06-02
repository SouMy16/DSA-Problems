//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSetUnion {
    public:
    vector<int> par;
    vector<int> sz;
    DisjointSetUnion(int n)
    {
        sz.resize(n+2, 1);
        for(int i=0; i<n+2; i++)
        {
            par.push_back(i);
        }
    }
    int findPar(int a)
    {
        return a == par[a] ? a : findPar(par[a]);
    }
    void combine(int a, int b)
    {
        int aa = a;
        int bb = b;
        a = findPar(a);
        b = findPar(b);
        if(a == b) 
        {
            // cout<<"no merger\n";
            return;
        }
        if(sz[a] >= sz[b])
        {
            // cout<<bb<<" merged in "<<aa<<'\n';
            par[b] = a;
            sz[a] += sz[b];
        }
        else{
            // cout<<aa<<" merged in "<<bb<<'\n';
            par[a] = b;
            sz[b] += sz[a];
        }
        return;
    }
    int mx()
    {
        int ans = 1;
        for(int i=0; i<sz.size(); i++)
        {
            // cout<<i+1<<" "<<sz[i]<<"\n";
            ans = max(ans, sz[i]);
        }
        return ans;
    }
};

class Solution {

public:
    vector<int> sieve;
    vector<int> primes;
    void precompute(){
        int n = 1e6+1;
        sieve.resize(n+1, 1);
        sieve[0] = 0;
        sieve[1] = 0;
        for(int i=2; i*i<n; i++)
        {
            if(sieve[i]==1)
            {
                primes.push_back(i);
                for(int j=i*i; j<n; j+=i)
                {
                    sieve[j] = 0;
                }
            }
        }
        for(int i = sqrt(n); i<n; i++) if(sieve[i] == 1) primes.push_back(i);
        return;
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        auto dsu = new DisjointSetUnion(n+1);
        if(m == 0) return -1;
        for(int i=0; i<g.size(); i++)
        {
            for(int j=0; j<g[i].size(); j++)
            {
                // cout<<i<<" "<<g[i][j]<<'\n';
                dsu->combine(i, g[i][j]);
            }
        }
        int k = dsu->mx();
        // cout<<k<<'\n';
        // for(int i=2; i<1e5+1; i++)
        // {
        //     if(sieve[i] == 1) k--;
        //     if(k == 0)
        //     {
        //         return i;
        //     }
        // }
        // cout<<primes.size()<<'\n';
        return primes[k-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends