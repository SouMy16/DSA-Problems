class Solution {
public:
    int dp1[1002][1002][4];
    int dp2[1002][1002][4];
    
    int Increasing(vector<int> &r, int ind, int prev, int cnt)
    {
        if(cnt==0) return 1;
        if(ind == r.size()) return 0;
        
        if(dp1[ind][prev+1][cnt] != -1) return dp1[ind][prev+1][cnt];
        
        int take=0, nottake=0;
        if(prev==-1)
        {
            take = Increasing(r, ind+1, ind, cnt-1);
        }
        else if(r[ind]>r[prev]) take = Increasing(r, ind+1, ind, cnt-1);
        
        nottake = Increasing(r, ind+1, prev, cnt);
        
        return dp1[ind][prev+1][cnt] = take + nottake;
    }
    
    int Decreasing(vector<int> &r, int ind, int prev, int cnt)
    {
        if(cnt==0) return 1;
        if(ind == r.size()) return 0;
        
        if(dp2[ind][prev+1][cnt] != -1) return dp2[ind][prev+1][cnt];
        
        int take=0, nottake=0;
        if(prev==-1)
        {
            take = Decreasing(r, ind+1, ind, cnt-1);
        }
        else if(r[ind]<r[prev]) take = Decreasing(r, ind+1, ind, cnt-1);
        
        nottake = Decreasing(r, ind+1, prev, cnt);
        
        return dp2[ind][prev+1][cnt] = take + nottake;
    }
    
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        
        int inc = Increasing(rating, 0, -1, 3);
        int dec = Decreasing(rating, 0, -1, 3);
        
        ans = inc + dec;
        return ans;
    }
};