class Solution {
public:
    long long coloredCells(int n) {
        return ((2*pow(n,2))-(2*n)+1);
    }
};