class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int len = requests.size();
        int total = pow(2, len);
        int maxi = 0;
        vector<int> res;
        for(int i =0;i<=total;i++){
            vector<int> req;
            for(int j = 0;j<len;j++){
                if((i>>j)&1) req.push_back(j);
            }
            vector<int> degree(n,0);
            for(auto j:req){
                degree[requests[j][0]]++;
                degree[requests[j][1]]--;
            }
            for(auto j:degree) {
                if(j!=0) {
                    req.clear();
                    break;
                }
            }
            maxi = max(maxi,(int)req.size());
        }
        return maxi;
    }
};