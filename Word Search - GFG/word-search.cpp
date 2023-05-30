//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isExist(vector<vector<char>> &board, string word, int i, int j, int k)
    {
        if(k >= word.size()) return true;
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0) return false;
        if(word[k] != board[i][j]) return false;
        bool ans = false;
        char c = board[i][j];
        board[i][j] = '#';
        ans = isExist(board, word, i-1, j, k+1) || isExist(board, word, i, j-1, k+1) || isExist(board, word, i+1, j, k+1) || isExist(board, word, i, j+1, k+1);
        // if(i>0) ans |= isExist(board, word, i-1, j, k+1);
        // if(j>0) ans |= isExist(board, word, i, j-1, k+1);
        // if(i<board.size()-1) ans |= isExist(board, word, i+1, j, k+1);
        // if(j<board[0].size()-1) ans |= isExist(board, word, i, j+1, k+1);
        board[i][j] = c;
        return ans;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        bool ans = false;
        int n = board.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                if(board[i][j] == word[0] && isExist(board, word, i, j, 0)) return true;
            }  
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends