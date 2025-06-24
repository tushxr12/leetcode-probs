//Recursion
class Solution {
private:
    int func(int ind)
    {
        if(ind <= 1)
            return 1;
        
        int poss1 = func(ind - 1);
        int poss2 = func(ind - 2);
        return (poss1 + poss2);
    }
public:
    int climbStairs(int n) {
        return func(n);
    }
};
