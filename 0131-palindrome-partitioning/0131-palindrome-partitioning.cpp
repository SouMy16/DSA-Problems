bool isPalindrome(string s){
    string x=s;
    reverse(x.begin(),x.end());
    return s==x;
}

void solve(string s, int ind, vector<string> temp, vector<vector<string>> &ans)
{
    if(ind==s.size())
    {
        ans.push_back(temp);
        return;
    }
    
    string x="";
    for(int i=ind;i<s.size();i++)
    {
        x+=s[i];
        if(isPalindrome(x)){
            temp.push_back(x);
            solve(s,i+1,temp,ans);
            temp.pop_back();
        }
    }
    return;
}

class Solution {
public: 
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> temp;
        solve(s,0,temp,ans);
        return ans;
    }
    
};