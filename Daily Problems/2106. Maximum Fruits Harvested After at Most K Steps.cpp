class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        vector<int> prefSum(n);
        vector<int> positions(n);

        for(int i = 0;i < n;i++){
            positions[i] = fruits[i][0];

            prefSum[i] = (i > 0 ? prefSum[i - 1] : 0) + fruits[i][1];
        }

        int maxFruits = 0;

        for(int d = 0;d <= k/2;d++)
        {
            int remain = k-2*d;
            int i = startPos - d;
            int j = startPos + remain;

            int left = lower_bound(begin(positions), end(positions), i) - begin(positions);
            int right = upper_bound(begin(positions), end(positions), j) - begin(positions) - 1;

            if(left <= right){
                int total = prefSum[right] - (left > 0 ? prefSum[left - 1] : 0);
                maxFruits = max(maxFruits , total);
            }

            // Second
            i = startPos - remain;
            j = startPos + d;

            left = lower_bound(begin(positions), end(positions), i) - begin(positions);
            right = upper_bound(begin(positions), end(positions), j) - begin(positions) - 1;
        
            if(left <= right){
                int total = prefSum[right] - (left > 0 ? prefSum[left - 1] : 0);
                maxFruits = max(maxFruits , total);
            }
        }

        return maxFruits;
    }
};
