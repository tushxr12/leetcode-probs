class Solution {
private:
    int f(int low,int high,int zero,int one,int len)
    {
        if(len > high)
            return 0;
        
        int zeroLen = len + zero;
        int oneLen = len + one;
        int zeroCount = (zeroLen >= low && zeroLen <= high) ? 1 : 0;
        int oneCount = (oneLen >= low && oneLen <= high) ? 1 : 0;
        int zeroRes = zeroCount + f(low, high,zero, one, zeroLen);
        int oneRes = oneCount + f(low, high, zero,one, oneLen);
        return (zeroRes + oneRes);
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        return f(low, high, zero, one, 0);
    }
};
