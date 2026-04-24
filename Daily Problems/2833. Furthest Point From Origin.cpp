class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, dash = 0;
        for(auto &ch : moves){
            if(ch == 'L')
                left++;
            else if(ch == 'R')
                right++;
            else
                dash++;
        }
        return abs(left - right) + dash;
    }
};
