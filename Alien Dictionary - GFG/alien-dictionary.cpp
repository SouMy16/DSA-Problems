//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Node{
  public:
  char val;
  vector<Node*> next;
  Node(char c){
      val = c;
  }
};


class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        //code here
        string ans = "";
        if(n == 0) return ans;
        Node* cur = new Node(dict[0][0]);
        // vector<Node*> g;
        vector<Node*> m(26, NULL);
        vector<int> in(26, 0);
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<min(dict[i].size(), dict[i+1].size()); j++)
            {
                if(dict[i][j] != dict[i+1][j])
                {
                    char c = dict[i][j];
                    char ch = dict[i+1][j];
                    if(m[c-'a'] == NULL) 
                    {
                        m[c-'a'] = new Node(c);
                        // g.push_back(m[c-'a']);
                    }
                    if(m[ch-'a'] == NULL) 
                    {
                        m[ch-'a'] = new Node(ch);
                        // g.push_back(m[ch-'a']);
                    }
                    m[c-'a']->next.push_back(m[ch-'a']);
                    in[ch-'a']++;
                    break;
                }
            }
        }
        queue<int> q;
        for(int i=0; i<26; i++) 
        {
            if(m[i] == NULL) in[i] = -1;
            if(in[i] == 0) q.push(i);
        }
        // cout<<q.front()<<"\n";
        // for(int i=0; i<26; i++)
        // {
        //     if(m[i] != NULL)
        //     {
        //         cout<<char('a'+i)<<"-> "<<in[i]<<" ";
        //         for(int j=0; j<m[i]->next.size(); j++)
        //         {
        //             cout<<m[i]->next[j]->val<<" ";
        //         }
        //         cout<<'\n';
        //     }
        // }
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            ans += char('a'+cur);
            for(int i=0; i<m[cur]->next.size(); i++)
            {
                in[m[cur]->next[i]->val - 'a']--;
                if(in[m[cur]->next[i]->val - 'a'] == 0) 
                {
                    q.push(m[cur]->next[i]->val - 'a');
                    // ans += m[cur]->next[i]->val;
                }
            }
        }
        // cout<<ans;
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends