class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        long long int ans = w;
        int n = capital.size();
        vector<vector<int>> m(n,vector<int>(2,0));
        for(int i=0; i<n; i++)
        {
            m[i][1] = profits[i];
            m[i][0] = capital[i];
        }
        sort(m.begin(), m.end());
        
        // for(int i=0; i<n; i++) cout<<m[i][0]<<" "<<m[i][1]<<'\n';
        
        priority_queue<int> pq;
        for(int i=0; i<n && k>0; i++)
        {
            if(m[i][0] <= w) pq.push(m[i][1]);
            else{
                if(pq.empty()) continue;
                ans += pq.top();
                w += pq.top();
                // cout<<"added "<<pq.top()<<'\n';
                pq.pop();
                k--;
                if(k == 0) return ans;
                // if(w < m[i][0]) break;
                while(w<m[i][0] && k > 0 && !pq.empty())
                {
                    k--;
                    w += pq.top();
                    ans += pq.top();
                    pq.pop();
                }
                if(k == 0) return ans;
                if(w<m[i][0]) return ans;
                pq.push(m[i][1]);
            }
            
//             if(m[i][0] <= w && i == n-1 && k>0)
//             {
//                 ans += pq.top();
//                 w += pq.top();
//                 // cout<<"added "<<pq.top()<<'\n';
//                 pq.pop();
//                 k--;
//                 // return ans;
//             }
        }
        while(k>0 && !pq.empty()) 
        {
            ans += pq.top();
            pq.pop();
            k--;
        }
        // cout<<pq.size()<<" "<<k<<'\n';
        return ans;
    }
};