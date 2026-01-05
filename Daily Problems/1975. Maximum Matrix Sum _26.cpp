class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        long long sum = 0;
        int negativeCount = 0;
        int mini = INT_MAX;

        // TC -> O(rows*cols)
        for(int i = 0;i < rows;i++)
        {
            for(int j = 0;j < cols;j++)
            {
                if(matrix[i][j] < 0)
                {
                    negativeCount+=1;
                }

                sum += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
            }
        }

        if(negativeCount%2)
            sum -= 2*mini;
        return sum;
    }
};
