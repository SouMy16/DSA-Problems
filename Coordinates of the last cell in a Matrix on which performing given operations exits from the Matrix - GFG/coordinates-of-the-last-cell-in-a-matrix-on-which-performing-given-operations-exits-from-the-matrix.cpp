//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        pair<int,int> ans;
        char direction = 'r';
        int i=0, j=0;
        int n = matrix.size();
        int m = matrix[0].size();
        int lasti = 0, lastj = 0;
        while(i<n && j<m && i>=0 && j>=0)
        {
            lasti = i, lastj = j;
            
            if(matrix[i][j] == 1)
            {
                matrix[i][j] = 0;
                if(direction == 'r') direction = 'd';
                else if(direction == 'l') direction = 'u';
                else if(direction == 'u') direction = 'r';
                else direction = 'l';
            }
            
            if(direction == 'r') j++;
            else if(direction == 'l') j--;
            else if(direction == 'u') i--;
            else i++;
        }
        ans = {lasti, lastj};
        return ans;
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends