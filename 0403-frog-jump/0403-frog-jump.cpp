class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> m;
    bool isPossible(vector<int> &stones, int ind, int prevjmp) {
        if(ind == stones.size()-1) return true;
        // if(ind == 0 && stones.size() > 1 && stones[1] != 1) return false;
        if(m.find(ind) != m.end() && m[ind].find(prevjmp) != m[ind].end()) return m[ind][prevjmp];
        bool ans = false;
        for(int nxt = ind+1; nxt < stones.size(); nxt++) {
            if(abs(abs(stones[nxt]-stones[ind]) - prevjmp) <= 1) {
                ans |= isPossible(stones, nxt, abs(stones[nxt]-stones[ind]));
            }   
            else if(stones[ind]+prevjmp+1 < stones[nxt]){
                break;
            }
        }
        return m[ind][prevjmp] = ans;
    }
    bool canCross(vector<int>& stones) {
        return isPossible(stones, 0, 0);
    }
};