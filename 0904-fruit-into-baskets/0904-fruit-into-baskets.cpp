class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int type1 = -1, type2 = -1;
        int cur = 0;
        int n = fruits.size();
        int start = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i=0; i<n; i++)
        {
            if(type1 == -1 || type2 == -1)
            {
                if(type1 == -1)
                {
                    type1 = fruits[i];
                    count1 = 1;
                }
                else if(fruits[i] != type1 && type2 == -1)
                {
                    type2 = fruits[i];
                    count2 = 1;
                }
                cur++;
                continue;
            }
            if(fruits[i] != type1 && fruits[i] != type2)
            {
                start = i;
                while(start > 0 && fruits[start-1] == fruits[i-1])
                {
                    start--;
                }
                type1 = fruits[start];
                type2 = fruits[i];
                ans = max(ans, cur);
                cur = i-start+1;
                continue;
            }
            cur++;
        }
        ans = max(ans, cur);
        return ans;
    }
};