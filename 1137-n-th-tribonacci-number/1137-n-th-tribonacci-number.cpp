class Solution {
public:
    int tribonacci(int n) {
        int p1, p2, p0;
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        p0=0;
        p1=1;
        p2=1;
        for(int i=3; i<n; i++)
        {
            p2 = p2+p1+p0;
            p1 = p2-p1-p0;
            p0 = p2-p1-p0;
        }
        return p0+p1+p2;
    }
};