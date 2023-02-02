class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> m;
        for(int i=0; i<26; i++) m[order[i]] = i;
        vector<string> v;
        for(int i=0; i<words.size(); i++)
        {
            string cur = "";
            for(int j=0; j<words[i].size(); j++)
            {
                cur += ('a'+m[words[i][j]]);
            }
            v.push_back(cur);
        }
        for(int i=0; i<v.size()-1; i++)
        {
            if(v[i] > v[i+1]) return false;
        }
        return true;
    }
};