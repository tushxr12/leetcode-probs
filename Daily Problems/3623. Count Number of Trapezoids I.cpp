class Solution {
public:
    const int mod = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<int,int> mpp;

        for(auto &i : points){
            int y = i[1];
            mpp[y]++;
        }

        long long traps = 0;

        long long prevHorizontalLines = 0;

        for(auto &i: mpp){
            long long cnt = i.second;

            long long currHorizontalLines = ((cnt)*(cnt-1))/2;

            traps += currHorizontalLines*prevHorizontalLines;
            prevHorizontalLines += currHorizontalLines;
        }
        return traps%mod;
    }
};
