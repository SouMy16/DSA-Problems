class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        int mnright = n;
        int mxleft = 0;
        for(int i=0; i<left.size(); i++) {
            mxleft = max(mxleft, left[i]);
        }
        for(int i=0; i<right.size(); i++) {
            mnright = min(mnright, right[i]);
        }
        return max(mxleft, n-mnright);
    }
};