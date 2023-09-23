class Solution {
public:
    bool compare(string a, string b) {
        int i=0, j=0;
        int ch=0;
        while(i<a.size() && j<b.size() && ch<=1) {
            if(a[i] != b[j]) {
                ch++;
                j++;
            }
            else i++, j++;
        }
        if(ch>1) return false;
        if(i==a.size() && j!=b.size() && ch==1) return false;
        return true;
    }

    map<string, int> m;
    int solve(vector<vector<string> > &v, int i, int j) {
        if(i+1 == v.size()) return 1;
        if(m.find(v[i][j]) != m.end()) return m[v[i][j]];
        int ans = 1;
        for(int k = 0; k < v[i+1].size(); k++) {
            // string v[i][k] -> v[i+1][k]
            if(compare(v[i][j], v[i+1][k])) {
                ans = max(ans, 1+solve(v, i+1, k));
            }
        }
        return m[v[i][j]] = ans;
    }

    int longestStrChain(vector<string>& words) {
        vector<vector<string> > v(17);
        int ans = 0;
        for(int i=0; i<words.size(); i++) {
            v[words[i].size()].push_back(words[i]);
        }
        for(int i=0; i<17; i++) {
            // check from smallest size
            for(int j=0; j<v[i].size(); j++) {
                // check for v[i]
                ans = max(ans, solve(v, i, j));
            }
        }
        return ans;
    }
};