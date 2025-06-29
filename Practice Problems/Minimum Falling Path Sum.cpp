//Recursion
class Solution {
private:
    int func(int i,int j, int n, int m, vector<vector<int>> &matrix)
    {
        if(j < 0 || j >= m)
            return 1e9;
        
        if(i == 0)
            return matrix[i][j];

        int top = matrix[i][j] + func(i - 1,j,n,m,matrix);
        int ld = matrix[i][j] + func(i-1,j-1,n,m,matrix);
        int rd = matrix[i][j] + func(i-1,j+1,n,m,matrix);

        return min({top, rd, ld});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int mini = INT_MAX;

        for(int j = 0;j < m;j++)
        {
            mini = min({mini, func(n-1,j,n,m,matrix)});
        }

        return mini;
    }
};
