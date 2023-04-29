// static bool mycomp(vector<int> a, vector<int> b)
// {
//     return a[2]<=b[2];
// }
// class Solution {
// public:
// //     bool dfs(int cur, int end, vector<vector<int>> &graph, int mx, int n, vector<int> &vis)
// //     {
// //         if(cur == end) return true;
// //         bool ans = false;
// //         for(int i=0; i<n; i++)
// //         {
// //             if(vis[i] == 0 && graph[cur][i] != 0 && mx>graph[cur][i])
// //             {
// //                 vis[i] = 1;
// //                 ans |= dfs(i, end, graph, mx, n, vis);
// //                 if(ans) return ans;
// //                 vis[i] = 0;
// //             }
// //         }
// //         return ans;
// //     }
    
// //     vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries)
// //     {
// //         vector<bool> ans(queries.size(), false);
// //         // map<pair<int,int>, int> graph;
// //         // for(int i=0; i<edgeList.size(); i++)
// //         // {
// //         //     if(graph[{edgeList[i][0], edgeList[i][1]}] == 0) 
// //         //     {
// //         //         graph[{edgeList[i][0], edgeList[i][1]}] = edgeList[i][2];
// //         //         graph[{edgeList[i][1], edgeList[i][0]}] = edgeList[i][2];
// //         //     }
// //         //     else 
// //         //     {
// //         //         graph[{edgeList[i][0], edgeList[i][1]}] = min(graph[{edgeList[i][0], edgeList[i][1]}], edgeList[i][2]);
// //         //         graph[{edgeList[i][1], edgeList[i][0]}] = min(graph[{edgeList[i][1], edgeList[i][0]}], edgeList[i][2]);
// //         //     }
// //         // }
        
// //         vector<vector<int>> graph(n+1, vector<int>(n+1, -1));
// //         for(int i=0; i<edgeList.size(); i++)
// //         {
// //             if(graph[edgeList[i][0]][edgeList[i][1]] == -1)
// //             {
// //                 graph[edgeList[i][0]][edgeList[i][1]] = edgeList[i][2];
// //                 graph[edgeList[i][1]][edgeList[i][0]] = edgeList[i][2];
// //             }
// //             else{
// //                 graph[edgeList[i][0]][edgeList[i][1]] = min(graph[edgeList[i][0]][edgeList[i][1]], edgeList[i][2]);
// //                 graph[edgeList[i][1]][edgeList[i][0]] = min(graph[edgeList[i][1]][edgeList[i][0]], edgeList[i][2]);
// //             }
// //         }
// //         for(int i=0; i<queries.size(); i++)
// //         {
// //             int st = queries[i][0];
// //             int end = queries[i][1];
// //             int mx = queries[i][2];
// //             vector<int> vis(n,0);
// //             ans[i]= dfs(st, end, graph, mx, n, vis);
// //         }
// //         return ans;
// //     }
    
//     map<int,int> parent;
    
//     void addNode(vector<int> edge, vector<vector<int>> &graph)
//     {
        
//     }
    
    
//     vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries){
//         int q = queries.size();
//         int e = edgeList.size();
//         vector<bool> ans(n);
//         for(int i=0; i<q; i++) queries[i].push_back(i);
//         sort(edgeList.begin(), edgeList.end(), mycomp);
//         sort(queries.begin(), queries.end(), mycomp);
//         int p=0;
//         vector<vector<int>> graph(n, vector<int>(n,-1));
//         for(int i=0; i<q; i++)
//         {
//             int ind = queries[i][3];
//             while(p<e && edgeList[p][2]<queries[i][2])
//             {
//                 addNode(edgeList[p], graph);
//                 p++;
//             }
//             if(parent[queries[i][0]] == parent[queries[i][1]]) ans[ind] = true;
//             else ans[ind] = false;
//         }
//         return ans;
//     }
// };


class Solution {
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }
    int find_prnt(int node, vector<int> &prnt) {
        if(node == prnt[node]) return node;
        return prnt[node] = find_prnt(prnt[node], prnt);
    }
    void unionn(int u, int v, vector<int> &prnt, vector<int> &rank) {
        int ulp_u = find_prnt(u, prnt), ulp_v = find_prnt(v, prnt);

        if(rank[ulp_u] > rank[ulp_v]) prnt[ulp_v] = ulp_u; 
        else if(rank[ulp_u] < rank[ulp_v]) prnt[ulp_u] = ulp_v;
        else {
            prnt[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int m = queries.size(), p = 0;
        for(int i=0; i<m; i++) queries[i].push_back(i);

        sort(edgeList.begin(), edgeList.end(), cmp);
        sort(queries.begin(), queries.end(), cmp);

        vector<bool> ans(m);
        vector<int> prnt(n), rank(n);
        for(int i=0; i<n; i++) prnt[i] = i;

        for(auto q : queries) {
            while(p < edgeList.size() && edgeList[p][2] < q[2]) {
                unionn(edgeList[p][0], edgeList[p][1], prnt, rank), p++;
            }
            ans[q[3]] = find_prnt(q[0], prnt) == find_prnt(q[1], prnt);
        }
        return ans;
    }
};