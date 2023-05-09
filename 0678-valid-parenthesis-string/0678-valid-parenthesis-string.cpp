class Solution {
public:
    bool checkValidString(string s) {
        int cur=0;
        int buf=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(') cur++;
            else if(s[i] == ')') cur--;
            else buf++;
            
            if(cur<0)
            {
                if(buf==0) return false; 
                buf--;
                cur++;
            }
        }
        if(cur>buf) return false;
        cur=0, buf=0;
        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i] == ')') cur++;
            else if(s[i] == '(') cur--;
            else buf++;
            
            if(cur<0)
            {
                if(buf==0) return false;
                buf--;
                cur++;
            }
        }
        if(cur>buf) return false;
        return true;
    }
};