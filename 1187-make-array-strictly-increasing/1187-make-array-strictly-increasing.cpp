class Solution {
public:
    int makeArrayIncreasing(vector<int>& box1, vector<int>& box2) {
            int n = box1.size();
            vector<vector<int>> A(2, vector<int>(n+1, INT_MAX));
            sort(box2.begin(), box2.end());
            box2.resize(unique(box2.begin(), box2.end()) - box2.begin());
            A[0][0] = box1[0];
            A[0][1] = box2[0];
            int last = 1;
            for (int i=1; i<n; i++) {
                int this_last = -1;
                for (int j=last; j>=0; j--) {
                    int &u = A[(i-1)%2][j];
                    if (u == INT_MAX)
                        break;
                    if (u < box1[i]) {
                        A[i%2][j] = min(A[i%2][j], box1[i]);
                        this_last = max(this_last, j);
                    }
                    auto it = upper_bound(box2.begin(), box2.end(), u);
                    if (it != box2.end()) {
                        int v = *it;
                        A[i%2][j+1] = min(A[i%2][j+1], v);
                        this_last = max(this_last, j+1);
                    }
                    u = INT_MAX;
                }
                last = this_last;
            }
            int ans = -1;
            for (int j=0; j<=n; j++) {
                if (A[(n-1)%2][j] != INT_MAX) {
                    ans = j;
                    break;
                }
            }
            return ans;
    }
};