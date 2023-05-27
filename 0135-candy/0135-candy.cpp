class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        map<int, vector<int>> m;
        for(int i=0; i<n; i++)
        {
            m[ratings[i]].push_back(i);
        }
        int ans = 0;
        vector<int> candies(n, 0);
        for(auto e:m)
        {
            vector<int> v = e.second;
            for(int i=0; i<v.size(); i++)
            {
                if(v[i]>0 && candies[v[i]-1] != 0 && ratings[v[i]-1] < ratings[v[i]])
                {
                    if(v[i]<n-1 && candies[v[i]+1] != 0 && ratings[v[i]+1] < ratings[v[i]])
                    {
                        candies[v[i]] = max(candies[v[i]+1], candies[v[i]-1]) + 1;
                    }
                    else candies[v[i]] = candies[v[i]-1] + 1;
                }
                else if(v[i]<n-1 && candies[v[i]+1] != 0 && ratings[v[i]+1] < ratings[v[i]])
                {
                    candies[v[i]] = candies[v[i]+1] + 1;
                }
                else candies[v[i]] = 1;
                ans += candies[v[i]];
            }
        }
        return ans;
    }
};