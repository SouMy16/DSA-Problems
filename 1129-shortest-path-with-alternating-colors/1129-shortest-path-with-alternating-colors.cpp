class Solution {
public:
    // void traverse(int &pos, int dis, char col, vector<int> &ans, map<int,vector<int>> &red, map<int,vector<int>> &blue, vector<int> &vis)
    // {
    //     if(ans[pos] == -1) ans[pos] = dis;
    //     if(dis > ans[pos]) return;
    //     ans[pos] = min(ans[pos], dis);
    //     // if(vis[pos] >= 1) return;
    //     // vis[pos]++;
    //     if(col == 'r')
    //     {
    //         for(int i=0; i<blue[pos].size(); i++)
    //         {
    //             if(blue[pos][i] == pos)
    //             {
    //                for(int i=0; i<red[pos].size(); i++)
    //                 {
    //                     if(red[pos][i] == pos) continue;
    //                     traverse(red[pos][i], dis+2, 'r', ans, red, blue, vis);
    //                 } 
    //                 continue;
    //             }
    //             traverse(blue[pos][i], dis+1, 'b', ans, red, blue, vis);
    //         }
    //     }
    //     else{
    //         for(int i=0; i<red[pos].size(); i++)
    //         {
    //             if(red[pos][i] == pos)
    //             {
    //                for(int i=0; i<blue[pos].size(); i++)
    //                 {
    //                     if(blue[pos][i] == pos) continue;
    //                     traverse(blue[pos][i], dis+2, 'b', ans, red, blue, vis);
    //                 } 
    //                 continue;
    //             }
    //             traverse(red[pos][i], dis+1, 'r', ans, red, blue, vis);
    //         }
    //     }
    //     return;
    // }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        vector<int> ans(n, -1);
        ans[0] = 0;
        map<int,vector<int>> red, blue;
        for(int i=0; i<redEdges.size(); i++) red[redEdges[i][0]].push_back(redEdges[i][1]);
        for(int i=0; i<blueEdges.size(); i++) blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        // int pos = 0;
        queue<vector<int>> q;
        q.push(vector<int>{0,0,-1});
        // vector<int> vis(n+1,-1);
        // vis[0] = 1;
        while(!q.empty())
        {
            int col = q.front()[2];
            int pos = q.front()[0];
            int dis = q.front()[1];
            q.pop();
            // vis[pos] = 1;
            if(ans[pos] == -1) ans[pos] = dis;
            // ans[pos] = min(ans[pos], dis);
            if(col == -1)
            {
                for(int i=0; i<red[pos].size(); i++)
                {
                    if(red[pos][i] != -1) 
                    {
                        q.push(vector<int>{red[pos][i], dis+1, 1});
                        red[pos][i] = -1;
                    }
                }
                
                for(int i=0; i<blue[pos].size(); i++)
                {
                    if(blue[pos][i] != -1) 
                    {
                        q.push(vector<int>{blue[pos][i], dis+1, 0});
                        blue[pos][i] = -1;
                    }
                }
            }
            else if(col == 1)
            {
                for(int i=0; i<blue[pos].size(); i++)
                {
                    if(blue[pos][i] != -1) 
                    {
                        q.push(vector<int>{blue[pos][i], dis+1, 0});
                        blue[pos][i] = -1;
                    }
                }
            }
            else if(col == 0)
            {
                for(int i=0; i<red[pos].size(); i++)
                {
                    if(red[pos][i] != -1) 
                    {
                        q.push(vector<int>{red[pos][i], dis+1, 1});
                        red[pos][i] = -1;
                    }
                }
            }
            // cout<<pos<<" "<<q.size()<<'\n';
        }
        return ans;
    }
};