class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = __builtin_popcount(n);
        return (n > 0 && cnt == 1);
    }
};
