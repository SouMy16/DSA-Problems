//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    map<int, map<int,int>> row, col, mat;
    public:
    
    int findMat(int x, int y){
        if(x<3){
            if(y<3) return 0;
            if(y<6) return 1;
            return 2;
        }
        if(x<6){
            if(y<3) return 3;
            if(y<6) return 4;
            return 5;
        }
        if(y<3) return 6;
        if(y<6) return 7;
        return 8;
    }
    
    bool solve(int grid[N][N]){
        int zero = 0;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(grid[i][j] == 0) zero++;
            }
        }
        if(zero == 0) return true;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(grid[i][j] == 0){
                    int mm = findMat(i, j);
                    for(int k=1; k<=9; k++){
                        if(row[i][k] == 0 && col[j][k] == 0 && mat[mm][k] == 0){
                            row[i][k] = 1;
                            col[j][k] = 1;
                            mat[mm][k] = 1;
                            grid[i][j] = k;
                            if(solve(grid)) return true;
                            row[i][k] = 0;
                            col[j][k] = 0;
                            mat[mm][k] = 0;
                            grid[i][j] = 0;
                        }
                    }
                    if(grid[i][j] == 0) return false;
                }
            }
        }
        return false;
    }
    
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(grid[i][j] != 0){
                    row[i][grid[i][j]] = 1;
                    col[j][grid[i][j]] = 1;
                    mat[findMat(i,j)][grid[i][j]] = 1;
                }
            }
        }
        if(solve(grid)) return true;
        return false;
    }
    
    
    
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends