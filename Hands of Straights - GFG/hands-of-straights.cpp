//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int gs, vector<int> &hand) {
        // code here
        map<int, int> m;
        for(int i=0; i<n; i++)
        {
            m[hand[i]]++;
        }
        // for(auto e:m) cout<<e.first<<" "<<e.second<<'\n';
        // cout<<'\n';
        // for(int i=0; i<n; i+=gs)
        // {
        int ele = 0;
        while(ele<n){
            int k = gs;
            int prev = -1;
            int skip = 0;
            for(map<int,int>::iterator e=m.begin(); e!=m.end(); e++)
            {
                if(skip)
                {
                    skip = 0;
                    continue;
                }
                int cur = e->first;
                ele++;
                if(prev==-1) prev = cur;
                else if(cur-prev>1) return false;
                else prev = cur;
                m[prev]--;
                k--;
                // cout<<prev<<" "<<m[prev]<<'\n';
                if(m[prev] == 0) 
                {
                    if(e!=m.begin()) skip = 1;
                    m.erase(m.find(prev));
                }
                if(k==0) 
                {
                    break;
                }
            }
            if(k!=0) return false;
        }
        // }
        if(ele<n) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends