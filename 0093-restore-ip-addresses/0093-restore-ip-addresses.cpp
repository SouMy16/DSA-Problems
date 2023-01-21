class Solution {
public:
    bool isValid(string &s)
    {
        int n1 = 0;
        int s1 = 0;
        int i = 0;
        int dot = 0;
        while(s[i]!='.')
        {
            n1*=10;
            n1+=s[i]-'0';
            i++;
        }
        dot++;
        if(n1>0 && s[s1]=='0') return false;
        if(i-s1>1 && n1 == 0) return false;
        if(n1 > 255) return false;
        
        i++;
        n1 = 0;
        s1 = i;
        while(s[i]!='.')
        {
            n1*=10;
            n1+=s[i]-'0';
            i++;
            if(i>=s.size()) return false;
        }
        dot++;
        if(n1>0 && s[s1]=='0') return false;
        if(i-s1>1 && n1 == 0) return false;
        if(n1 > 255) return false;
        
        i++;
        n1 = 0;
        s1 = i;
        while(s[i]!='.')
        {
            n1*=10;
            n1+=s[i]-'0';
            i++;
            if(i>=s.size()) return false;
        }
        dot++;
        if(n1>0 && s[s1]=='0') return false;
        if(i-s1>1 && n1 == 0) return false;
        if(n1 > 255) return false;
        
        i++;
        n1 = 0;
        s1 = i;
        while(s[i]!='.')
        {
            n1*=10;
            n1+=s[i]-'0';
            i++;
            if(i>=s.size()) break;
        }
        dot++;
        if(n1>0 && s[s1]=='0') return false;
        if(i-s1>1 && n1 == 0) return false;
        if(n1 > 255) return false;
        
        if(i<s.size()) return false;
        
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> answer;
        if(s.size() < 4) return answer;
        set<string> ans;
        for(int i=1; i<=3; i++)
        {
            for(int j=i+1; j<=i+3; j++)
            {
                for(int k=j+1; k<=j+3; k++)
                {
                    for(int l=k+1; l<=k+3; l++)
                    {
                        string cur = "";
                        int f = 0;
                        for(int a=0; a<n; a++)
                        {
                            if((f==0) && (a==i || a==j || a==k || a==l))
                            {
                                a--;
                                f = 1;
                                cur.push_back('.');
                            }
                            else{
                                f = 0;
                                cur.push_back(s[a]);
                            }
                        }
                        // cout<<cur<<"   ";
                        if(isValid(cur)) ans.insert(cur);
                    }
                }
            }
        }
        for(auto ele:ans) answer.push_back(ele);
        return answer;
    }
};