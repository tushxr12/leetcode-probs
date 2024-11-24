class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int countNegatives = 0;
        int mini = INT_MAX;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] < 0)
                    countNegatives++;
                mini = min(mini, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }
        return (countNegatives%2 == 0)? sum : sum - 2*abs(mini);
    }
};
