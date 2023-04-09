class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        int n = digits.size();
        for(int i=0; i<n; i++)
        {
            digits[i] = digits[i]+carry;
            carry = digits[i]/10;
            digits[i] %= 10;
        }
        if(carry != 0)
        {
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};