//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void DFS(vector<vector<int>> &adj, int cur, vector<int> &sorted, vector<int> &vis)
	{
	    vis[cur] = 1;
	    for(int i=0; i<adj[cur].size(); i++)
	    {
	        if(!vis[adj[cur][i]]) DFS(adj, adj[cur][i], sorted, vis);
	    }
	    sorted.push_back(cur);
	    return;
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(n, 0);
        vector<int> sorted;
        for(int i=0; i<n; i++) if(!vis[i]) DFS(adj, i, sorted, vis);
        
        // for(int i=0; i<n; i++) cout<<sorted[i]<<' ';
        // cout<<'\n';
        
        for(int i=0; i<n; i++) vis[i] = 0;
        vector<vector<int>> nadj(n);
        for(int i=0; i<adj.size(); i++)
        {
            for(int j=0; j<adj[i].size(); j++)
            {
                nadj[adj[i][j]].push_back(i);
                // cout<<adj[i][j]<<"->"<<i<<'\n';
            }
        }
        int ans = 0;
        vector<vector<int>> answer;
        for(int i=sorted.size()-1; i>=0; i--)
        {
            if(!vis[sorted[i]])
            {
                // cout<<sorted[i]<<" ";
                ans++;
                vector<int> component;
                DFS(nadj, sorted[i], component, vis);
                answer.push_back(component);
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
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends