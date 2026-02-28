class Solution {
public:
    int mod = 1e9 + 7;

    int concatenatedBinary(int n) {
        long result = 0;
        int digits = 0;
        
        for(int num = 1; num <= n;num++){
            if((num & (num - 1)) == 0)
                digits++;
            result = ((result << digits)%mod + num)%mod; 
        }

        return result;
    }
};
