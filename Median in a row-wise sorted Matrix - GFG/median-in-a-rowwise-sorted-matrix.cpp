//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int countLess(vector<int> &a, int r)
    {
        int low = 0, high = a.size()-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(a[mid] >= r) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
    
    int countMore(vector<int> &a, int r)
    {
        int low = 0, high = a.size()-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(a[mid] <= r) low = mid+1;
            else high = mid-1;
        }
        return a.size()-low;
    }

    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int high = 0, low = matrix[0][0];
        for(int i=0; i<r; i++) 
        {
            high = max(high, matrix[i][c-1]);
            low = min(low, matrix[i][0]);
        }
        int mid;
        int n = r*c;
        n++;
        n /= 2;
        
        while(low <= high)
        {
            mid = low+(high-low)/2;
            int less=0, more=0, equal = 0;
            for(int i=0; i<r; i++)
            {
                less += countLess(matrix[i], mid);
                more += countMore(matrix[i], mid);
            }
            equal = (r*c)-less-more;
            
            if(less >= n) 
                high = mid-1;
            else if(more >= n) 
                low = mid+1;
            else if(less + equal >= n && more + equal >= n) 
            {
                if(equal != 0) 
                    return mid;
                else if(more > less) less = mid+1;
                else high = mid-1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends