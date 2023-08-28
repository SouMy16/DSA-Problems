//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool findWord(int x, int xc, int y, int yc, vector<vector<char>> &grid, string &word, int ind) {
        if(ind == word.size()) return true;
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) return false;
        if(word[ind] != grid[x][y]) return false;
        if(ind == word.size()-1) return true;
        if(x+xc<0 || x+xc>=grid.size() || y+yc<0 || y+yc>=grid[0].size()) return false;
        if(findWord(x+xc, xc, y+yc, yc, grid, word, ind+1)) return true;
        
        return false;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>> grid, string word) {
	    // Code here
	    vector<vector<int>> ans;
	    int xc[8] = {0,0,+1,+1,+1,-1,-1,-1};
        int yc[8] = {+1,-1,0,+1,-1,0,+1,-1};
	    for(int i=0; i<grid.size(); i++) {
	        for(int j=0; j<grid[i].size(); j++) {
	            if(grid[i][j] == word[0]) {
	               // cout<<i<<" "<<j<<'\n';
    	            for(int k=0; k<8; k++) { 
                        if(findWord(i, xc[k], j, yc[k], grid, word, 0)) 
                        {
                            ans.push_back(vector<int>{i, j});
                            break;
                        }
    	            }
	            }
            }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends