class Solution {
public:
    bool isBarpatite1(vector<vector<int>>&graph, int i, vector<int>&color)
    {
        color[i]=1;
        queue<pair<int,int>> q;
        q.push({i,-1});
        while(!q.empty())
        {
            int cur = q.front().first;
            int par = q.front().second;
            q.pop();
            if(par==-1) color[cur] = 1;
            else if(color[cur] == color[par]) return false;
            else color[cur] = 1-color[par];
            for(int j=0;j<graph[cur].size();j++)
            {
                if(color[graph[cur][j]]==-1)
                {
                    q.push({graph[cur][j],cur});
                } else if(color[graph[cur][j]]==color[cur]) return false;
            }
        }
        return true;
    }
    
    
    bool isBarpartite2(vector<vector<int>>& graph,int i,vector<int> &color){
        if(color[i]==-1) color[i]=1;
        for(int j=0;j<graph[i].size();j++)
        {
            if(color[graph[i][j]]==-1){
                color[graph[i][j]]=1-color[i];
                if(!isBarpartite2(graph, graph[i][j], color)) return false;
            }
            else if(color[i] == color[graph[i][j]]) return false;
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) 
    {   
        vector<int> color(graph.size(),-1);   
        int n = graph.size();
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!isBarpatite1(graph, i, color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};