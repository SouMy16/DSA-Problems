class Solution {
    vector<int> parent, rank;
    int count;
    int findParent(int node){
        if (parent[node] != node){
            parent[node] = findParent(parent[node]);
        }
        return parent[node];
    }
    void union_(int idx1, int idx2){
        int root1 = findParent(idx1);
        int root2 = findParent(idx2);
        if (root1 == root2){
            return;
        }
        if (rank[root2]< rank[root1]){
            parent[root2] = root1;
        }else if (rank[root2]>rank[root1]){
            parent[root1] = root2;
        }else{
            parent[root1] = root2;
            rank[root2]++;
        }
        count--;
    }
    bool isSimilar(string& a, string& b){
        int diff = 0;
        for(int i=0; i<a.size(); i++){
            if (a[i] != b[i]){
                diff++;
            }
        }
        return diff == 0 || diff == 2;
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        for(int i=0; i<n; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
        count = n;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if (isSimilar(strs[i], strs[j])){
                    union_(i, j);
                }
            }
        }
        return count;
    }
};