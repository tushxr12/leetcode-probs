class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsNum2 = __builtin_popcount(num2);
        int bit = 31;
        int res = 0;
        while(bit >= 0 && setBitsNum2 > 0)
        {
            //Check if bit is set in num1, and if it is, set it in res as well
            if((num1 & (1 << bit)) != 0)
            {
                res = res | (1 << bit);
                setBitsNum2--;
            }
            bit--;
        }

        bit = 0;
        while(setBitsNum2 > 0 && bit <= 32)
        {
            if((num1 & (1 << bit)) == 0)
            {
                res = res | (1 << bit);
                setBitsNum2--;
            }
            bit++;
        }
        return res;
    }
};
