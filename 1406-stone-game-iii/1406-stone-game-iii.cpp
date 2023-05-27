class Solution {
public:
    
    string stoneGameIII(vector<int>& stoneValue) 
    {
        vector<int> memo(stoneValue.size(), INT_MAX);
       int value = stoneGame(memo, stoneValue,0);    
       if(value > 0)
           return "Alice";
        else if(value  < 0)
            return "Bob";
        else
            return "Tie";
    }
    
    int stoneGame(vector<int>& memo, const vector<int>& stones, int i)
    {
        if(i>=stones.size())
            return 0;
        
        if(memo[i]!=INT_MAX)
            return memo[i];
        
        int sum =  stones[i];        
        int value = sum - stoneGame(memo, stones, i+1); 
        
        for(int j = i+1; j < min(i+3, (int)stones.size()); ++j)
        {
            sum+=stones[j];
            value = max(value, sum - stoneGame(memo, stones, j+1));
        }
        memo[i] = value;
        return memo[i];
        
    }
};