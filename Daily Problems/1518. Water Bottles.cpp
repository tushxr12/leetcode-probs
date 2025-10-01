class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = numBottles;
        int ans = numBottles;

        while(emptyBottles >= numExchange){
            int refilled = emptyBottles/numExchange;
            int rem = emptyBottles%numExchange;
            ans += refilled;

            emptyBottles = rem + refilled;
        }
        return ans;
    }
};
