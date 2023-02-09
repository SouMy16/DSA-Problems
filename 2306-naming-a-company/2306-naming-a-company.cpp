class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long int ans = 0;
        set<string> ss[26];
        int n = ideas.size();
        for(int i=0; i<n; i++)
        {
            ss[ideas[i][0]-'a'].insert(ideas[i].substr(1));
        }
        
        for(int i=0; i<26; i++)
        {
            for(int j = i+1; j<26; j++)
            {
                long long int c1 = 0;
                long long int c2 = 0;
                for(auto it: ss[i]) if(ss[j].find(it) == ss[j].end()) c1++;
                for(auto it: ss[j]) if(ss[i].find(it) == ss[i].end()) c2++;
                ans += (c1*c2);
            }
        }
        return ans*2;
    }
};