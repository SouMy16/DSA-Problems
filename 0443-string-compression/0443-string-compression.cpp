class Solution {
public:
	int compress(vector<char>& chars) {
		int ans = 1;
        int c = 1;
        if(chars.size() < 2) return chars.size();
        for(int i=1; i<chars.size(); i++)
        {
            if(chars[i] != chars[i-1])
            {
                if(c == 1)
                {
                    chars[ans] = chars[i];
                    ans++;
                }
                else{
                    string x = to_string(c);
                    for(int i=0; i<x.size(); i++)
                    {
                        chars[ans] = x[i];
                        ans++;
                    }
                    chars[ans] = chars[i];
                    ans++;
                }
                c = 1;
            }
            else c++;
        }
        if(c>1)
        {
            string x = to_string(c);
            for(int i=0; i<x.size(); i++)
            {
                chars[ans] = x[i];
                ans++;
            }
            // chars[ans] = chars[i];
            // ans++;
        }
        return ans;
	}
};