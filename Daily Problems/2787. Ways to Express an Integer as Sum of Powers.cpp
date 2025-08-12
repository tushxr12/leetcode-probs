// Brute
class Solution {
private:
    int solve(int n,int num,int x){
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 0;
        
        int currPowerValue = pow(num, x);
        if(currPowerValue > n)
            return 0;
        
        int take = solve(n - currPowerValue, num + 1,x);
        int skip = solve(n, num + 1, x);

        return (take + skip);
    }
public:
    int numberOfWays(int n, int x) {
        return solve(n, 1, x);
    }
};
