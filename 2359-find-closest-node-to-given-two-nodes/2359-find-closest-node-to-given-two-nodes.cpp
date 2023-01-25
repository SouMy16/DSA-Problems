class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int ans = -1;
        int mndist = INT_MAX;
        int dist1 = 0, dist2 = 0;
        // map<int,int> m1, m2;
        int n = edges.size();
        vector<int> m1(n,-1), m2(n,-1);
        int pos = node1;
        m1[pos] = 0;
        while(edges[pos] != -1)
        {
            // cout<<"m1 "<<pos<<"->"<<edges[pos]<<" "<<m1[pos]<<" "<<dist1<<'\n';
            pos = edges[pos];
            if(m1[pos] != -1) break;
            dist1++;
            m1[pos] = dist1;
        }
        pos = node2;
        m2[pos] = 0;
        while(edges[pos] != -1)
        {
            // cout<<"m2 "<<pos<<"->"<<edges[pos]<<'\n';
            pos = edges[pos];
            if(m2[pos] != -1) break;
            dist2++;
            m2[pos] = dist2;
        }
        for(int i=0; i<edges.size(); i++)
        {
            // cout<<i<<" "<<m1[i]<<" "<<m2[i]<<'\n';
            if(m1[i] == -1 || m2[i] == -1) continue;
            if(mndist > max(m1[i], m2[i])) 
            {
                ans = i;
                mndist = max(m1[i], m2[i]);
            }
            else if(mndist == max(m1[i], m2[i])) ans = min(ans, i);
        }
        if(mndist == INT_MAX) ans = -1;
        return ans;
    }
};