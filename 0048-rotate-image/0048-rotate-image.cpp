class Solution {
public:
    void rotate(vector<vector<int>>& a) {
       int n = a.size();
        for(int i=0; i<n/2; i++)
        {
            for(int j=i; j<n-1-i; j++)
            {
                int w = a[i][j];
                int x = a[j][n-1-i];
                int y = a[n-1-i][n-1-j];
                int z = a[n-1-j][i];

                a[n-1-j][i] = w;
                a[i][j] = x;
                a[n-1-i][n-1-j] = z;
                a[j][n-1-i] = y;
            }
        }
        for(int i=0; i<n/2; i++)
        {
            for(int j=i; j<n-1-i; j++)
            {
                int w = a[i][j];
                int x = a[j][n-1-i];
                int y = a[n-1-i][n-1-j];
                int z = a[n-1-j][i];

                a[n-1-j][i] = w;
                a[i][j] = x;
                a[n-1-i][n-1-j] = z;
                a[j][n-1-i] = y;
            }
        }
        for(int i=0; i<n/2; i++)
        {
            for(int j=i; j<n-1-i; j++)
            {
                int w = a[i][j];
                int x = a[j][n-1-i];
                int y = a[n-1-i][n-1-j];
                int z = a[n-1-j][i];

                a[n-1-j][i] = w;
                a[i][j] = x;
                a[n-1-i][n-1-j] = z;
                a[j][n-1-i] = y;
            }
        }
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         cout<<a[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        return;
    }
};