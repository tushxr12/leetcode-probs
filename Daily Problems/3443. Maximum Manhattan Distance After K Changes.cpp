class Solution {
public:
    int maxDistance(string s, int k) {
        int maxMD = 0;
        int north = 0, south = 0, east = 0, west = 0;

        for(int i = 0;i < s.size();i++)
        {
            if(s[i] == 'E') east++;
            else if(s[i] == 'S') south++;
            else if(s[i] == 'N') north++;
            else west++;

            int currMD = abs(east - west) + abs(north - south);
            int steps = i + 1;
            int wasted = steps - currMD;
            int extra = 0;
            if(wasted != 0)
            {
                extra = min(2*k, wasted);
            }

            int finalCurrMD = currMD + extra;

            maxMD = max(maxMD, finalCurrMD);
        }
        return maxMD;
    }
};
