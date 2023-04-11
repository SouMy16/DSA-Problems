class Solution {
public:
    string removeStars(string s) {
        string ans="";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '*'){
                ans.pop_back();
                // i = max(i,0);
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};