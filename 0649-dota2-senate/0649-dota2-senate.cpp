class Solution {
public:
    string predictPartyVictory(string senate) {
    int n = senate.length();
        queue<int>rad;
        queue<int>dire;

        for(int i=0; i<n; i++){
            if(senate[i]=='R'){
                rad.push(i);
            }else{
                dire.push(i);
            }
        }

        if(rad.size()==0)   return "Dire";
        if(dire.size()==0)  return "Radiant";

        while(!rad.empty() && !dire.empty()){
            if(rad.front() < dire.front()){
                dire.pop();
                int  r = rad.front();
                rad.push(n+r);
                rad.pop();
            }else{
                rad.pop();
                int d = dire.front();
                dire.push(n+d);
                dire.pop();
            }
        }
        return rad.size()==0 ? "Dire":"Radiant";
    }
};