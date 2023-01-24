class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int pos = 1;
        vector<int> DBoard(1,0);
        int x = 1;
        if(board.size()%2==0) x=0;
        for(int i=board.size()-1; i>=0; i--)
        {
            if(i%2 == x) reverse(board[i].begin(), board[i].end());
            for(int j=0; j<board[i].size(); j++)
            {
                DBoard.push_back(board[i][j]);
            }
        }
        int n = DBoard.size()-1;
        int ans = INT_MAX;
        queue<pair<int,int>> q;
        q.push({1,0});
        vector<int> vis(n+1,0);
        while(!q.empty())
        {
            int pos = q.front().first;
            int cur = q.front().second;
            if(pos == n)
            {
                ans = min(ans, cur);
            }
            q.pop();
            if(vis[pos] == 1) continue;
            for(int i=1; i<=6 and pos+i<=n; i++)
            {
                if(DBoard[pos+i] == -1)
                {
                    q.push({pos+i, cur+1});
                }
                else if(DBoard[pos+i] != -1)
                {
                    q.push({DBoard[pos+i], cur+1});
                }
            }
            vis[pos] = 1;
        }
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
};