class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k = 1;k <= 60;k++){
            long long target = num1 - 1LL * num2 * k;
            if(target < k)
                return -1;
            long setBits = __builtin_popcountll(target);
            if(setBits <= k)
                return (int)k;
        }
        return -1;
    }
};
