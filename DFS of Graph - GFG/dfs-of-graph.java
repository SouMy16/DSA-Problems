//{ Driver Code Starts
// Initial Template for Java
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int V = Integer.parseInt(s[0]);
            int E = Integer.parseInt(s[1]);
            ArrayList<ArrayList<Integer>> adj =
                new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < V; i++) adj.add(new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                String[] S = br.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            Solution obj = new Solution();
            ArrayList<Integer> ans = obj.dfsOfGraph(V, adj);
            for (int i = 0; i < ans.size(); i++)
                System.out.print(ans.get(i) + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    
    void DFS(int i, ArrayList<ArrayList<Integer>> adj, ArrayList<Integer> vis, int v, ArrayList<Integer> ans) {
        if(vis.get(i) == 1) return;
        vis.set(i, 1);
        ans.add(i);
        for(int j=0; j<adj.get(i).size(); j++) {
            if(vis.get(adj.get(i).get(j)) == 0) {
                DFS(adj.get(i).get(j), adj, vis, v, ans);
            }
        }
        return;
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    public ArrayList<Integer> dfsOfGraph(int v, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        ArrayList<Integer> vis = new ArrayList<Integer>();
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i=0; i<v; i++) vis.add(0);
        for(int i=0; i<v; i++) {
            if(vis.get(i) == 0) DFS(i, adj, vis, v, ans);
        }
        return ans;
    }
}