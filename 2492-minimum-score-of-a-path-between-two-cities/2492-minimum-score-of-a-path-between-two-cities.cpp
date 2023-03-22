struct node{
    int parent;
    int ans;
};

// int findParent(int x)
// {
    
// }

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        node a[n+1];
        for(int i=1; i<=n; i++)
        {
            // a[i] = new node();
            a[i].parent = i;
            a[i].ans = INT_MAX;
        }
        for(int i=0; i<roads.size(); i++)
        {
            int x = roads[i][0];
            int y = roads[i][1];
            int v = roads[i][2];
            
            while(a[x].parent != x) x = a[x].parent;
            while(a[y].parent != y) y = a[y].parent;
            // a[x].parent = findParent(a, x);
            // a[y].parent = findParent(a, y);
            
            a[x].ans = min(v, min(a[x].ans, a[y].ans));
            a[y].ans = a[x].ans;
            
            if(y<x) a[x].parent = y;
            else a[y].parent = x;
        }
        return a[1].ans;
    }
};