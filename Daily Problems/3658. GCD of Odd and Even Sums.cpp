class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0;
        int evenSum = 0;
        int cnt = n;
        int i = 1;
        while(cnt--)
        {
            oddSum += i;
            i += 2;
        }

        cnt = n;
        i = 2;
        while(cnt--)
        {
            evenSum += i;
            i += 2;
        }

        int ans = __gcd(evenSum, oddSum);
        return ans;
    }
};
