class Solution {
public:
    bool canAliceWin(int n) {
        int take = 10;
        int steps = 0;

        while(n >= take)
        {
            n -= take;
            take--;
            steps += 1;
        }

        if(steps%2)
            return true;
        return false;
    }
};
