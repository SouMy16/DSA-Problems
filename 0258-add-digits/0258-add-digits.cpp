class Solution {
public:
    int addDigits(int num) {
        while(num > 9)
        {
            int cur = 0;
            while(num)
            {   
                cur += num%10;
                num/=10;
            }
            num = cur;
        }
        return  num;
    }
};